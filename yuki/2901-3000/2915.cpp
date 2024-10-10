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

int N,M,T;
int U[1010],V[1010],W[1010];
int dis[1010];

vector<int> E[1010];
int dp[1010];
int P[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>T;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		U[i]--,V[i]--;
		E[U[i]].push_back(i);
	}
	FOR(i,N) dp[i]=-1<<30;
	
	dp[0]=0;
	priority_queue<pair<int,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		int co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(co!=dp[cur]) continue;
		FORR(e,E[cur]) if(dis[e]==0 && chmax(dp[V[e]],co+W[e])) Q.push({-dp[V[e]],V[e]});
	}
	FOR(i,M) {
		W[i]=dp[V[i]]-dp[U[i]]+W[i];
	}
	
	FOR(i,N) P[i]=dp[i];
	
	while(T--) {
		cin>>x;
		dis[x-1]^=1;
		FOR(i,N) dp[i]=-1<<30;
		
		dp[0]=0;
		priority_queue<pair<int,int>> Q;
		Q.push({0,0});
		while(Q.size()) {
			int co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(co!=dp[cur]) continue;
			FORR(e,E[cur]) if(dis[e]==0 && chmax(dp[V[e]],co+W[e])) Q.push({-dp[V[e]],V[e]});
		}
		int ret=dp[N-1];
		if(ret==-1<<30) {
			cout<<"NaN"<<endl;
		}
		else {
			cout<<ret-P[N-1]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
