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
vector<pair<int,int>> E[2][202020];

ll dp[2][2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		x--,y--;
		E[0][x].push_back({y,k});
		E[1][y].push_back({x,k});
	}
	FOR(i,2) FOR(j,2) FOR(x,N) dp[i][j][x]=1LL<<60;
	dp[0][0][N-2]=0;
	dp[1][0][N-2]=0;
	dp[0][1][N-1]=0;
	dp[1][1][N-1]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0*2*N+0*N+N-2});
	Q.push({0,1*2*N+0*N+N-2});
	Q.push({0,0*2*N+1*N+N-1});
	Q.push({0,1*2*N+1*N+N-1});
	while(Q.size()) {
		ll co=-Q.top().first;
		int id=Q.top().second/(2*N);
		int id2=Q.top().second/N%2;
		int cur=Q.top().second%N;
		Q.pop();
		if(dp[id][id2][cur]!=co) continue;
		FORR2(e,c,E[id][cur]) if(dp[id][id2][e]>co+c) {
			dp[id][id2][e]=co+c;
			Q.push({-dp[id][id2][e],id*(2*N)+id2*N+e});
		}
	}
	FOR(i,N-2) {
		ll ret=1LL<<60;
		ret=min(ret,dp[1][0][i]+dp[0][0][N-1]+dp[0][1][i]);
		ret=min(ret,dp[1][1][i]+dp[0][1][N-2]+dp[0][0][i]);
		if(ret==1LL<<60) ret=-1;
		cout<<ret<<endl;
	}
	
			
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
