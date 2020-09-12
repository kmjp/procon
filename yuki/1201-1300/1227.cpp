#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,C;
int S[3];
vector<int> E[1010];
int V[1010];
ll dp[1010][6010];
const ll mo=1000000007;

void dfs(int cur,int pre) {
	int i;
	FOR(i,C) dp[cur][i]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		
		FOR(i,C) {
			ll cand=0;
			if(i-3>=0) cand+=dp[e][i-3];
			if(i+3<C) cand+=dp[e][i+3];
			dp[cur][i]=dp[cur][i]*cand%mo;
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	ll ret=0;
	if(C>6*N) {
		ret=C-(6*N);
		C=6*N;
		FOR(i,N-1) ret=ret*2%mo;
	}
	
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	FOR(i,C) ret+=dp[0][i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
