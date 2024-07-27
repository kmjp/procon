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

int N,M,K;
vector<pair<int,int>> E[4040];

ll dp[4040][4040];
ll dp2[4040][1<<9];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	K--;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	FOR(i,K) {
		FOR(j,N) dp[i][j]=1LL<<60;
		dp[i][i]=0;
		priority_queue<pair<ll,int>> Q;
		Q.push({0,i});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[i][cur]!=co) continue;
			FORR2(e,c,E[cur]) if(chmin(dp[i][e],co+c)) Q.push({-dp[i][e],e});
		}
	}
	int mask,mask2;
	FOR(mask,1<<K) FOR(i,N) {
		FOR(j,K) if(mask&(1<<j)) dp2[i][mask]+=dp[j][i];
	}
	FOR(mask,1<<K) {
		for(int sm=mask;sm>=0;sm--) {
			sm&=mask;
			int sm2=mask^sm;
			FOR(i,N) FORR2(j,c,E[i]) dp2[i][mask]=min(dp2[i][mask],dp2[i][sm]+dp2[j][sm2]+c);
		}
		priority_queue<pair<ll,int>> Q;
		FOR(i,N) Q.push({-dp2[i][mask],i});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp2[cur][mask]!=co) continue;
			FORR2(e,c,E[cur]) if(chmin(dp2[e][mask],co+c)) Q.push({-dp2[e][mask],e});
		}
		
	}
	for(i=K;i<N;i++) cout<<dp2[i][(1<<K)-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
