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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1LL<<60;
	V comp(V l,V r){ return min(l,r);};
	
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

SegTree_1<ll,1<<20> st1,st3;

int N,E,T;
ll X[202020];
ll R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>E>>T;
	
	
	x=0;
	X[N+1]=E;
	for(i=1;i<=N;i++) cin>>X[i];
	
	st1.update(0,0);
	st3.update(0,-2*X[1]);
	for(i=1;i<=N;i++) {
		while(2*(X[i]-X[x+1])>T) x++;
		
		R[i]=min(3*X[i]+st3.getval(0,x), X[i]+T+st1.getval(x,i));
		st1.update(i,R[i]-X[i]);
		st3.update(i,R[i]-(X[i]+2*X[i+1]));
	}
	
	cout<<R[N]+E-X[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
