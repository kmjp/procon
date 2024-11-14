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

int T,N,M;
vector<pair<int,int>> E[1010];
int S[1010];
ll dp[1010][1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) E[i].clear();
		FOR(i,M) {
			cin>>x>>y>>k;
			E[x-1].push_back({y-1,k});
			E[y-1].push_back({x-1,k});
		}
		FOR(i,N) cin>>S[i];
		FOR(i,N) FOR(j,1010) dp[i][j]=1LL<<60;
		priority_queue<pair<ll,int>> Q;
		dp[0][S[0]]=0;
		Q.push({0,S[0]});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second/10000;
			int b=Q.top().second%10000;
			Q.pop();
			if(dp[cur][b]!=co) continue;
			if(cur==N-1) {
				cout<<co<<endl;
				break;
			}
			FORR2(e,w,E[cur]) if(chmin(dp[e][min(b,S[e])],co+w*b)) Q.push({-dp[e][min(b,S[e])],e*10000+min(b,S[e])});
		}
	}
		
			
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
