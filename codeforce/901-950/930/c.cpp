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

int T,H,W;
int C[404040];
vector<int> A[404040];

vector<ll> dp[404040];
vector<vector<pair<pair<int,int>,int>>> E[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) cin>>C[y];
		
		FOR(y,H) {
			A[y].resize(W);
			FOR(x,W) cin>>A[y][x];
			dp[y].clear();
			E[y].clear();
			dp[y].resize(W+1);
			E[y].resize(W+1);
			FOR(x,W+1) dp[y][x]=1LL<<60;
		}
		FOR(x,W) {
			vector<pair<int,int>> V;
			FOR(y,H) V.push_back({A[y][x],y});
			sort(ALL(V));
			FOR(y,H-1) {
				E[V[y].second][x].push_back({{V[y+1].second,x},0});
				E[V[y+1].second][x].push_back({{V[y].second,x},V[y+1].first-V[y].first});
			}
			FOR(y,H) {
				E[y][x].push_back({{y,W},C[y]});
				E[y][W].push_back({{y,x},0});
			}
		}
		dp[0][W]=0;
		priority_queue<pair<ll,pair<int,int>>> Q;
		Q.push({0LL,{0,W}});
		while(Q.size()) {
			ll co=-Q.top().first;
			y=Q.top().second.first;
			x=Q.top().second.second;
			Q.pop();
			if(dp[y][x]!=co) continue;
			FORR2(e,c,E[y][x]) {
				int ty=e.first;
				int tx=e.second;
				if(chmin(dp[ty][tx],co+c)) Q.push({-dp[ty][tx],{ty,tx}});
			}
		}
		cout<<dp[H-1][W]<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
