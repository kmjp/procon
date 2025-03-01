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

int N,M,X;
vector<pair<int,int>> E[202020];
ll dp[202020][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back({y-1,0});
		E[y-1].push_back({x-1,1});
	}
	FOR(i,N) dp[i][0]=dp[i][1]=1LL<<60;
	dp[0][0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second/2;
		int id=Q.top().second%2;
		Q.pop();
		if(dp[cur][id]!=co) continue;
		if(chmin(dp[cur][id^1],co+X)) Q.push({-dp[cur][id^1],cur*2+(id^1)});
		
		FORR2(e,a,E[cur]) if(id==a&&chmin(dp[e][id],co+1)) Q.push({-dp[e][id],e*2+id});
		
	}
	cout<<min(dp[N-1][0],dp[N-1][1])<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
