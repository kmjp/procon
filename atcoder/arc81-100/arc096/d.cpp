#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll C;
ll X[101010],V[101010];
ll ret;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
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

SegTree_1<ll,1<<20> st,st2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	FOR(i,N) cin>>X[i+1]>>V[i+1];
	
	
	// R->L
	ll sum=0;
	for(i=1;i<=N;i++) {
		sum+=V[i];
		st.update(i,sum-2*X[i]);
	}
	sum=0;
	for(i=N;i>=1;i--) {
		sum+=V[i];
		ret=max(ret,sum-(C-X[i])+st.getval(0,i));
	}
	
	// L->R
	sum=0;
	for(i=N;i>=1;i--) {
		sum+=V[i];
		st2.update(i,sum-2*(C-X[i]));
	}
	sum=0;
	for(i=1;i<=N;i++) {
		sum+=V[i];
		ret=max(ret,sum-X[i]+st2.getval(i+1,N+1));
	}
	
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
