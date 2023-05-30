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

int N,M,C;
int A[202020];
int L[202020],R[202020];
ll dp[202020];

vector<pair<int,int>> E[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>C;
	ll sum=0;
	FOR(i,N) {
		cin>>A[i];
		sum+=A[i];
		E[i].push_back({i+1,A[i]});
		E[i+1].push_back({i,A[i]});
	}
	FOR(i,M) {
		cin>>L[i]>>R[i];
		E[L[i]-1].push_back({R[i],C});
		E[R[i]].push_back({L[i]-1,C});
	}
	FOR(i,N+1) dp[i]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	dp[0]=0;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dp[cur]!=co) continue;
		FORR2(e,c,E[cur]) if(chmin(dp[e],co+c)) Q.push({-dp[e],e});
	}
	cout<<sum-dp[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
