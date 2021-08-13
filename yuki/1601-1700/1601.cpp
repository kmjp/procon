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

int N,M;
int A[202020],B[202020],C[202020],X[202020];
vector<pair<int,int>> E[202020];

ll dp[202020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i]>>X[i];
		A[i]--;
		B[i]--;
		E[A[i]].push_back({B[i],i});
		E[B[i]].push_back({A[i],i});
	}
	FOR(i,N) dp[i][0]=dp[i][1]=1LL<<60;
	dp[N-1][0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,N-1});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second%N;
		int did=Q.top().second/N;
		Q.pop();
		if(dp[cur][did]!=co) continue;
		FORR2(e,i,E[cur]) {
			int tar=did|X[i];
			if(dp[e][tar]>co+C[i]) {
				dp[e][tar]=co+C[i];
				Q.push({-dp[e][tar],tar*N+e});
			}
		}
	}
	FOR(i,N-1) cout<<dp[i][1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
