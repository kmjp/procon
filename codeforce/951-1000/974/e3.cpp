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

int T,N,M,H;
int A[202020];
vector<pair<int,int>> E[202020];
ll dp[202020][2][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		
		cin>>N>>M>>H;
		FOR(i,N) {
			dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=1LL<<60;
			E[i].clear();
			A[i]=0;
		}
		FOR(i,H) {
			cin>>x;
			A[x-1]=1;
		}
		FOR(i,M) {
			cin>>x>>y>>k;
			E[x-1].push_back({y-1,k/2});
			E[y-1].push_back({x-1,k/2});
		}
		dp[0][0][0]=0;
		dp[N-1][1][0]=0;
		priority_queue<pair<ll,int>> Q;
		Q.push({0,0});
		Q.push({0,(N-1)*4+2});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second/4;
			int id=Q.top().second/2%2;
			int h=Q.top().second%2;
			Q.pop();
			if(co!=dp[cur][id][h]) continue;
			if(A[cur]==1&&chmin(dp[cur][id][1],co)) Q.push({-dp[cur][id][1],cur*4+id*2+1});
			if(chmin(dp[cur][id][0],co)) Q.push({-dp[cur][id][0],cur*4+id*2+0});
			FORR2(e,c,E[cur]) if(chmin(dp[e][id][h],co+c*(2-h))) Q.push({-dp[e][id][h],e*4+id*2+h});
		}
		ll mi=1LL<<60;
		FOR(i,N) mi=min(mi,max(dp[i][0][0],dp[i][1][0]));
		if(mi==1LL<<60) mi=-1;
		cout<<mi<<endl;
			
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
