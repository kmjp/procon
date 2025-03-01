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

int N,K,Q;
ll C[88][88];

ll dp[1<<9][88][88];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(y,N) FOR(x,N) cin>>C[y][x];
	FOR(k,N) FOR(x,N) FOR(y,N) C[x][y]=min(C[x][y],C[x][k]+C[k][y]);
	int mask;
	FOR(mask,2<<K) FOR(x,N) FOR(y,N) dp[mask][x][y]=1LL<<60;
	
	FOR(k,N) if(k>=K) {
		FOR(i,K) dp[1<<i][k][i]=0;
		dp[1<<K][k][k]=0;
		
		FOR(mask,2<<K) {
			for(int sm=(mask-1);sm>0;sm--) {
				sm=sm&(mask);
				int tm=mask^sm;
				FOR(x,N) chmin(dp[mask][k][x],dp[sm][k][x]+dp[tm][k][x]);
			}
			
			priority_queue<pair<ll,int>> Q;
			FOR(i,N) Q.push({-dp[mask][k][i],i});
			while(Q.size()) {
				ll co=-Q.top().first;
				int cur=Q.top().second;
				Q.pop();
				if(dp[mask][k][cur]!=co) continue;
				FOR(x,N) if(chmin(dp[mask][k][x],co+C[cur][x])) Q.push({-dp[mask][k][x],x});
			}
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		cout<<dp[(2<<K)-1][x-1][y-1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
