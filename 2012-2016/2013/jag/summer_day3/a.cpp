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

int N,D;
ll X;
ll P[10][10];

ll dp[11][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D>>X;
	FOR(i,D) FOR(x,N) cin>>P[i][x];
	
	FOR(i,D-1) {
		FOR(y,11) FOR(x,101000) dp[y][x]=-1LL<<60;
		dp[0][X]=0;
		
		FOR(x,N) {
			for(y=100000;y>=0;y--) {
				dp[x+1][y]=max(dp[x+1][y],dp[x][y]);
				if(y>=P[i][x]) dp[x+1][y-P[i][x]]=max(dp[x+1][y-P[i][x]],dp[x+1][y]+P[i+1][x]);
			}
		}
		
		X=-1LL<<60;
		FOR(x,101000) X=max(X,dp[N][x]+x);
	}
	cout<<X<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
