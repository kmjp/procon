#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,H[100100];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	H[0]=H[N+1]=1000000;
	FOR(i,N) cin>>H[i+1];
	FOR(i,N+2) st.update(i,H[i]);
	
	for(i=1;i<=N;i++) {
		j=0;
		for(x=19;x>=0;x--) {
			if(i-(j+(1<<x))>=0 && st.getval(i-(j+(1<<x)),i)<=H[i]) j+=1<<x;
		}
		y=j;
		j=0;
		for(x=19;x>=0;x--) {
			if(i+(j+(1<<x))<=N+1 && st.getval(i,i+(j+(1<<x)))<=H[i]) j+=1<<x;
		}
		_P("%d\n",y+j-1);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
