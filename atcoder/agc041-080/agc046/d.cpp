#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


string S;
int N;
const ll mo=998244353;

ll dp[303][303][303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	dp[0][0][0]=1;
	FOR(i,N) {
		FOR(x,N) FOR(y,N) if(dp[i][x][y]) {
			if(x) {
				dp[i+1][x][y]=1;
				if(S[i]=='1') dp[i+1][x-1][y+1]=1;
			}
			if(y) {
				dp[i+1][x][y]=1;
				if(S[i]=='0') dp[i+1][x+1][y-1]=1;
			}
			if(i+2<=N) {
				if(S[i]=='0') dp[i+2][x+1][y]=1;
				else dp[i+2][x][y+1]=1;
				if(S[i+1]=='0') dp[i+2][x+1][y]=1;
				else dp[i+2][x][y+1]=1;
			}
		}
	}
	
	for(i=N;i>=0;i--) {
		FOR(x,N) FOR(y,N) if(dp[i][x][y]) {
			int a=x,b=y;
			for(j=i-1;j>=0;j--) {
				if(S[j]=='0') a--;
				else b--;
				if(a>=0 && b>=0) dp[j][a][b]=0;
			}
		}
	}
	
	FOR(i,N) {
		if(S[i]=='0') {
			FOR(y,N+1) for(x=N;x>=1;x--) (dp[i][y][x-1]+=dp[i][y][x])%=mo;
		}
		else {
			FOR(y,N+1) for(x=N;x>=1;x--) (dp[i][x-1][y]+=dp[i][x][y])%=mo;
		}
		FOR(y,N+1) {
			FOR(x,N+1) (dp[i+1][x][y]+=dp[i][x][y])%=mo;
		}
	}
	for(int t=N;t>=0;t--) FOR(x,t+1) {
		y=t-x;
		if(x) (dp[N][x-1][y]+=dp[N][x][y])%=mo;
		if(y) (dp[N][x][y-1]+=dp[N][x][y])%=mo;
		
	}
	cout<<dp[N][0][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
