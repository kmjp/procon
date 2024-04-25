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

int N,W,D;
int dp[2][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W>>D;
	FOR(i,W+1) dp[0][i]=dp[1][i]=-1<<30;
	dp[0][0]=dp[1][0]=0;
	
	while(N--) {
		int t,w,v;
		cin>>t>>w>>v;
		for(i=5000-w;i>=0;i--) dp[t][i+w]=max(dp[t][i+w],dp[t][i]+v);
	}
	
	int ma=0;
	FOR(x,W+1) FOR(y,W+1) if(x+y<=W&&abs(x-y)<=D) {
		ma=max(ma,dp[0][x]+dp[1][y]);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
