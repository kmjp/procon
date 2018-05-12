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

int N;
int pos[2][2020];
int L[2][2020][2020];
int dp[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N) {
		cin>>s>>x;
		pos[s=="W"][x-1]=i;
	}
	
	FOR(i,2) {
		FOR(x,N) {
			for(y=x+1;y<N;y++) if(pos[i][y]<pos[i][x]) L[i][x][N]++;
			for(y=N-1;y>=0;y--) L[i][x][y]=L[i][x][y+1]+(pos[i^1][y]<pos[i][x]);
		}
	}
	
	FOR(x,N+2) FOR(y,N+2) dp[x][y]=1<<25;
	dp[0][0]=0;
	FOR(x,N+1) FOR(y,N+1) {
		if(x<N) dp[x+1][y]=min(dp[x+1][y],dp[x][y]+L[0][x][y]);
		if(y<N) dp[x][y+1]=min(dp[x][y+1],dp[x][y]+L[1][y][x]);
	}
	
	cout<<dp[N][N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
