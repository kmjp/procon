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
int C[101010];
vector<pair<int,int>> E[101010];
ll dp[4][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) cin>>C[i];
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back({y-1,C[i]});
		E[y-1].push_back({x-1,C[i]});
	}
	FOR(i,N) FOR(j,K+1) dp[j][i]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	FOR(i,K+1) {
		dp[i][0]=0;
		Q.push({0,i*N});
	}
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second%N;
		int id=Q.top().second/N;
		Q.pop();
		if(dp[id][cur]!=co) continue;
		FORR2(e,c,E[cur]) {
			if(id&&chmin(dp[id-1][e],co)) Q.push({-dp[id-1][e],(id-1)*N+e});
			if(chmin(dp[id][e],co+c)) Q.push({-dp[id][e],(id)*N+e});
		}
	}
	ll ret=dp[0][N-1];
	if(ret>=1LL<<59) ret=-1;
	cout<<ret<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
