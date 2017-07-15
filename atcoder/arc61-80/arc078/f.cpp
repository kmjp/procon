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
int mat[101][101];
int dp[1<<15][15];
int cost[1<<15][15];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		mat[x-1][y-1]=r;
		mat[y-1][x-1]=r;
	}
	
	FOR(i,1<<N) {
		FOR(x,N) {
			dp[i][x]=1<<30;
			FOR(y,N) if(i&(1<<y)) cost[i][x]+=mat[x][y];
		}
	}
	
	dp[1][0]=0;
	for(int mask=0;mask<1<<N;mask++) {
		FOR(x,N) if((mask&(1<<x)) && dp[mask][x]<1<<30) {
			FOR(y,N) if(mat[x][y] && (mask&(1<<y))==0) {
				int addco=cost[mask][y]-mat[x][y];
				dp[mask|(1<<y)][y]=min(dp[mask|(1<<y)][y],dp[mask][x]+addco);
			}
			
			int nmask=mask^(1<<x);
			int left=((1<<N)-1)^mask;
			for(int i=left; i>0; i=(i-1)&left) {
				int add=0;
				FOR(y,N) if(i&(1<<y)) add+=cost[nmask][y];
				dp[mask|i][x]=min(dp[mask|i][x],dp[mask][x]+add);
			}
		}
	}
	
	cout<<dp[(1<<N)-1][N-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
