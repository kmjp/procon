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
	static V const def=0;
	V comp(V l,V r){ return l|r;};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 0;
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

int N;
int T[505050];
int V[505050];
int col[1010101];
ll dp[505050];
int pre[1005050];
int preb[20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(col);
	FOR(i,N) {
		cin>>T[i];
		pre[i]=col[T[i]];
		col[T[i]]=i;
	}
	
	FOR(i,N) {
		cin>>V[i];
		st.update(i,V[i]);
	}
	FOR(j,20) preb[j]=-1;
	int pp=-1;
	FOR(i,N) {
		pp=max(pp,pre[i]);
		dp[i+1]=dp[pp+1]+st.getval(pp+1,i+1);
		FOR(j,20) {
			x = max(pp,preb[j]);
			dp[i+1]=min(dp[i+1],dp[x+1]+st.getval(x+1,i+1));
			if(V[i]&(1<<j)) preb[j]=i;
		}
	}
	cout<<dp[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
