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
int A[16][16];
int dp[1<<16][16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(A);
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		x--,y--;
		A[x][y]=A[y][x]=max(A[y][x],r);
	}
	
	MINUS(dp);
	FOR(i,N) dp[1<<i][i]=0;
	int mask;
	int ma=0;
	FOR(mask,1<<N) FOR(i,N) if(dp[mask][i]>=0) {
		ma=max(ma,dp[mask][i]);
		FOR(x,N) if(A[i][x]>=0 && (mask&(1<<x))==0) dp[mask|(1<<x)][x]=max(dp[mask|(1<<x)][x],dp[mask][i]+A[i][x]);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
