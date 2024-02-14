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

int N;
int A[202020],B[202020],X[202020];
ll dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) {
		if(i<N) cin>>A[i]>>B[i]>>X[i];
		dp[i]=1LL<<60;
	}
	priority_queue<pair<ll,int>> Q;
	dp[1]=0;
	Q.push({0,1});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dp[cur]!=co) continue;
		if(cur==N) continue;
		if(dp[cur+1]>dp[cur]+A[cur]) {
			dp[cur+1]=dp[cur]+A[cur];
			Q.push({-dp[cur+1],cur+1});
		}
		if(dp[X[cur]]>dp[cur]+B[cur]) {
			dp[X[cur]]=dp[cur]+B[cur];
			Q.push({-dp[X[cur]],X[cur]});
		}
			
		
	}
	cout<<dp[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
