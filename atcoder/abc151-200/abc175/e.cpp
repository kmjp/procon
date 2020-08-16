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

int H,W,K;
int T[3030][3030];
ll dp[3030][3030][4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(i,K) {
		cin>>y>>x>>r;
		T[y-1][x-1]=r;
	}
	
	FOR(y,H) FOR(x,W) {
		for(i=2;i>=0;i--) dp[y][x][i+1]=max(dp[y][x][i+1],dp[y][x][i]+T[y][x]);
		
		FOR(i,4) {
			dp[y+1][x][0]=max(dp[y+1][x][0],dp[y][x][i]);
			dp[y][x+1][i]=max(dp[y][x+1][i],dp[y][x][i]);
		}
	}
	
	
	cout<<dp[H][W-1][0]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
