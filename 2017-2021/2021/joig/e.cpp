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

int N,M,L;
vector<pair<int,int>> E[1010],F[1010];
ll dp[1010][1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		F[y-1].push_back({x-1,r});
	}
	FOR(i,1010) FOR(j,1010) dp[i][j]=1LL<<60;
	dp[0][0]=0;
	FOR(i,1005) {
		priority_queue<pair<ll,int>> Q;
		FOR(j,N) if(dp[i][j]<=L) Q.push({-dp[i][j],j});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[i][cur]!=co||co>L) continue;
			if(cur==N-1) {
				cout<<i<<endl;
				return;
			}
			FORR2(e,c,E[cur]) if(dp[i][e]>co+c) {
				dp[i][e]=co+c;
				Q.push({-dp[i][e],e});
			}
			FORR2(e,c,F[cur]) dp[i+1][e]=min(dp[i+1][e],co+c);
		}
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
