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

int dp[202020][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) {
		if(S[i]=='R') x=0;
		if(S[i]=='P') x=1;
		if(S[i]=='S') x=2;
		
		dp[i+1][0]=dp[i+1][1]=dp[i+1][2]=-1<<30;
		
		FOR(j,3) FOR(k,3) {
			if(i&&j==k) continue;
			if(k==x) dp[i+1][k]=max(dp[i+1][k],dp[i][j]);
			if(k==(x+1)%3) dp[i+1][k]=max(dp[i+1][k],dp[i][j]+1);
		}
		
	}
	cout<<max({dp[N][0],dp[N][1],dp[N][2]})<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
