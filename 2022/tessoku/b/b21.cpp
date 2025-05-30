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
int dp[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) dp[i][i]=1;
	FOR(i,N-1) dp[i][i+1]=2-(S[i]!=S[i+1]);
	for(int len=2;len<=N-1;len++) {
		for(i=0;i+len<N;i++) {
			dp[i][i+len]=max(dp[i][i+len],dp[i][i+len-1]);
			dp[i][i+len]=max(dp[i][i+len],dp[i+1][i+len]);
			if(S[i]==S[i+len]) dp[i][i+len]=max(dp[i][i+len],dp[i+1][i+len-1]+2);
		}
	}
	cout<<dp[0][N-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
