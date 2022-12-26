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
ll dp[202020];
int A[202020],M[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,N+1) dp[i]=-1LL<<60;
	cin>>N>>K;
	dp[0]=0;
	for(i=1;i<=N;i++) {
		cin>>A[i]>>M[i];
		dp[i]=dp[0]-A[i];
		FOR(x,M[i]) {
			cin>>y;
			dp[i]=max(dp[i],dp[y]);
		}
		dp[0]=max(dp[0],dp[i]+A[i]);
	}
	
	ll ma=dp[0];
	FOR(i,N) ma=max(ma,dp[i+1]+A[i+1]);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
