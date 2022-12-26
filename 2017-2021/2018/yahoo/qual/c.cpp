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
ll X[20],C[20],V[20];

ll ret[20];
ll CC[1<<18];
ll VV[1<<18];

ll memo[1<<18];

ll dfs(int mask) {
	
	if(memo[mask]>=0) return memo[mask];
	if(mask==0) return 0;
	
	ll ma=0;
	int sell=N-__builtin_popcount(mask);
	ll M=0;
	int i;
	FOR(i,sell) M+=X[i];
	for(int j=mask; j>=0; j--) {
		j&=mask;
		if(CC[j]<=M) ma=max(ma,VV[j]);
	}
	
	
	
	ll del=1LL<<60;
	FOR(i,N) if(mask&(1<<i)) {
		del=min(del,dfs(mask^(1<<i)));
	}
	return memo[mask]=max(del,ma);
}




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>N;
	FOR(i,N) cin>>X[i];
	FOR(i,N) cin>>C[i];
	FOR(i,N) cin>>V[i];
	
	for(int mask=0;mask<1<<N;mask++) {
		FOR(i,N) if(mask&(1<<i)) {
			CC[mask] += C[i];
			VV[mask] += V[i];
		}
	}
	
	cout<<dfs((1<<N)-1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
