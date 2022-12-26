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
int W[300];
int mat[300][300];
ll mo=1000000007;

ll dp[1010][1010];
ll fact[1010];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	fact[0]=dp[0][0]=1;
	for(i=1;i<=1000;i++) {
		fact[i]=fact[i-1]*i%mo;
		dp[i][1]=1;
		for(j=2;j<=i;j++) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]*j)%mo;
	}
	
	cin>>N>>M;
	FOR(i,N) cin>>W[i], mat[i][i]=W[i];
	FOR(i,M) {
		cin>>x>>y, x--, y--;
		mat[x][y]=min(W[x],W[y]);
	}
	
	FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y] = max(mat[x][y], min(mat[x][z],mat[z][y]));
	
	ll ret=0;
	FOR(x,N) FOR(y,N) if(mat[x][y]>=W[y]) ret +=(dp[W[x]][W[y]] * fact[W[y]])%mo;
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
