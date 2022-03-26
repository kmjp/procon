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
int A[202020],B[202020];
int dp[202020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	dp[0][0]=dp[0][1]=1;
	for(i=1;i<N;i++) {
		if(dp[i-1][0]&&abs(A[i]-A[i-1])<=K) dp[i][0]=1;
		if(dp[i-1][1]&&abs(A[i]-B[i-1])<=K) dp[i][0]=1;
		if(dp[i-1][0]&&abs(B[i]-A[i-1])<=K) dp[i][1]=1;
		if(dp[i-1][1]&&abs(B[i]-B[i-1])<=K) dp[i][1]=1;
	}
	if(dp[N-1][0]||dp[N-1][1]) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
