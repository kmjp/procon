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

int N,K;
ll R[5050],X[5050];

ll dp[5050];
vector<pair<int,ll>> E[5050];
const ll C=1LL<<60;

void dfs(int cur,int pre) {
	FORR2(e,c,E[cur]) if(e!=pre) {
		dp[e]=dp[cur]+c;
		dfs(e,cur);
	}
}

int hoge(int v) {
	int i;
	FOR(i,N+1) E[i].clear();
	FOR(i,N) {
		if(i==v) {
			E[i].push_back({R[i],C});
			E[R[i]].push_back({i,-C});
		}
		else {
			E[i].push_back({R[i],X[i]});
			E[R[i]].push_back({i,-X[i]});
		}
	}
	dp[0]=0;
	dfs(0,0);
	ll L=-1LL<<50,R=1LL<<50;
	FOR(i,N) {
		if(abs(dp[i]-dp[i+1])<=C/2) {
			if(dp[i+1]-dp[i]<0) return 0;
			if(dp[i+1]-dp[i]>K) return 0;
		}
		else if(dp[i+1]>C/2) {
			L=max(L,dp[i]-(dp[i+1]-C));
			R=min(R,dp[i]-(dp[i+1]-C)+K);
		}
		else if(dp[i]>C/2) {
			L=max(L,dp[i+1]-(dp[i]-C)-K);
			R=min(R,dp[i+1]-(dp[i]-C));
		}
		else if(dp[i+1]<-C/2) {
			L=max(L,(dp[i+1]+C)-dp[i]-K);
			R=min(R,(dp[i+1]+C)-dp[i]);
		}
		else if(dp[i]<-C/2) {
			L=max(L,(dp[i]+C)-dp[i+1]);
			R=min(R,(dp[i]+C)-dp[i+1]+K);
		}
		else {
			assert(0);
		}
		
	}
	return (L<=R);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>R[i]>>X[i];
	FOR(i,N) {
		if(hoge(i)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
