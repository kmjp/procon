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
string S;
int A,B,C;
ll dp[5][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>A>>B>>C;
	FOR(i,5) FOR(j,N+1) dp[i][j]=1LL<<60;
	dp[0][0]=0;
	FOR(i,N) {
		dp[0][i+1]=dp[0][i]+A;
		dp[1][i+1]=min(dp[0][i],dp[3][i])+((S[i]=='R')?0:C);
		dp[2][i+1]=dp[1][i]+((S[i]=='G')?0:C);
		dp[3][i+1]=dp[2][i]+((S[i]=='B')?0:C);
		dp[4][i+1]=min({dp[0][i],dp[3][i],dp[4][i]})+B;
	}
	cout<<min({dp[0][N],dp[3][N],dp[4][N]})<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
