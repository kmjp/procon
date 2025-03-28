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

int T,N,A[202020];

int dp[2][202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i+1];
		
		FOR(i,N+3) dp[0][i]=dp[1][i]=1<<30;
		dp[0][0]=0;
		dp[1][0]=1<<20;
		dp[0][1]=1;
		dp[0][2]=1+(A[1]!=A[2]);
		dp[1][2]=2+(A[1]!=A[2]);
		for(i=3;i<=N;i++) {
			dp[0][i]=min(dp[0][i-1]+(A[i-1]!=A[i]),dp[1][i-1]+(A[i-2]!=A[i]));
			dp[1][i]=min(dp[0][i-2]+(A[i-1]!=A[i])+(A[i-2]!=A[i]),dp[1][i-2]+(A[i-1]!=A[i])+(A[i-3]!=A[i]))+1;
		}
		cout<<min(dp[0][N],dp[1][N])<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
