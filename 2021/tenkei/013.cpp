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

int N,M;
vector<pair<int,int>> E[101010];
ll dp[202020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	FOR(i,N) dp[i][0]=dp[i][1]=1LL<<60;
	dp[0][0]=dp[N-1][1]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	Q.push({0,N+N-1});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second%N;
		int id=Q.top().second/N;
		Q.pop();
		if(dp[cur][id]!=co) continue;
		FORR2(e,c,E[cur]) if(dp[e][id]>co+c) {
			dp[e][id]=co+c;
			Q.push({-dp[e][id],id*N+e});
		}
	}
	
	FOR(i,N) cout<<dp[i][0]+dp[i][1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
