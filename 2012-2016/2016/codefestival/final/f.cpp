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
ll dp[303][303][303];
ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	if(M<N) return _P("0\n");
	dp[0][1][1]=1; // as, tot
	FOR(i,M) {
		FOR(x,N+1) FOR(y,N+1) if(dp[i][x][y]) {
			ll t=dp[i][x][y];
			// loop
			(dp[i+1][y][y] += t*x)%=mo;
			// already
			(dp[i+1][x][y] += t*(y-x))%=mo;
			// new
			if(y<N) (dp[i+1][x][y+1] += t*(N-y))%=mo;
		}
	}
	
	cout<<dp[M][N][N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
