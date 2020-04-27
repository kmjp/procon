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

int N,M;
vector<vector<int>> E[51];
int S;
int D[50],C[50];
ll dp[51][2525];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	S=min(2500,S);
	FOR(i,M) {
		cin>>x>>y>>j>>r;
		E[x-1].push_back({y-1,j,r});
		E[y-1].push_back({x-1,j,r});
	}
	FOR(i,N) cin>>C[i]>>D[i];
	
	FOR(i,N) FOR(x,2501) dp[i][x]=1LL<<60;
	dp[0][S]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,S});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second/10000;
		int S=Q.top().second%10000;
		Q.pop();
		if(co!=dp[cur][S]) continue;
		
		if(S<2500) {
			if(dp[cur][min(2500,S+C[cur])]>co+D[cur]) {
				dp[cur][min(2500,S+C[cur])]=co+D[cur];
				Q.push({-dp[cur][min(2500,S+C[cur])], cur*10000+min(2500,S+C[cur])});
			}
		}
		FORR(e,E[cur]) if(S>=e[1]) {
			if(dp[e[0]][S-e[1]]>co+e[2]) {
				dp[e[0]][S-e[1]]=co+e[2];
				Q.push({-dp[e[0]][S-e[1]], e[0]*10000+S-e[1]});
			}
		}
	}
	
	for(i=1;i<N;i++) {
		ll mi=1LL<<60;
		FOR(j,2501) mi=min(mi,dp[i][j]);
		cout<<mi<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
