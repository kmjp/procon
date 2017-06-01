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

int N,M;
int D[101];

int dp[105][205][105];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,105) FOR(x,205) FOR(y,105) dp[i][x][y]=-1<<30;
	
	dp[0][102][M]=0;
	FOR(i,N) {
		cin>>D[i];
		FOR(x,205) FOR(y,105) if(dp[i][x][y]>-1<<30) {
			if(D[i]==0) {
				j=max(x+1,103);
				dp[i+1][j][y]=max(dp[i+1][j][y],dp[i][x][y]+(j-102));
			}
			else {
				if(y) {
					j=max(x+1,103);
					dp[i+1][j][y-1]=max(dp[i+1][j][y-1],dp[i][x][y]+(j-102));
				}
				j=min(x-1,101);
				dp[i+1][j][y]=max(dp[i+1][j][y],dp[i][x][y]+(j-102));
			}
		}
	}
	int ma=-1<<30;
	FOR(x,205) FOR(y,105) ma=max(ma,dp[N][x][y]);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
