#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M,C;
vector<pair<int,int>> E[202020];
ll dp[3][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>C;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k+C});
		E[y-1].push_back({x-1,k+C});
	}
	FOR(i,N) dp[0][i]=dp[1][i]=dp[2][i]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	dp[0][0]=dp[1][N-1]=dp[2][N-1]=0;
	Q.push({0,0});
	Q.push({0,N+N-1});
	Q.push({0,2*N+N-1});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second%N;
		int id=Q.top().second/N;
		Q.pop();
		if(dp[id][cur]!=co) continue;
		FORR2(e,c,E[cur]) if(chmin(dp[id][e],co+c)) Q.push({-dp[id][e],id*N+e});
		if(id==1) {
			FORR2(e,c,E[cur]) if(chmin(dp[2][e],co+C)) Q.push({-dp[2][e],2*N+e});
		}
	}
	
	ll ret=dp[0][N-1];
	for(i=1;i<N;i++) {
		ll mi=min(ret,dp[0][i]+dp[2][i]);
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
