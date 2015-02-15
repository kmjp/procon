#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,K;
int mat[100][100];
int dp[1<<17][17];
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(x,100) FOR(y,100) mat[x][y]=1000;
	FOR(x,100) mat[x][x]=0;
	FOR(i,M) {
		cin>>x>>y;
		mat[x-1][y-1]=mat[y-1][x-1]=1;
	}
	FOR(i,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
	V.push_back(0);
	
	ll ret=0;
	for(i=N-1;i>0;i--) {
		if(V.size()>=K+1) break;
		
		V.push_back(i);
		memset(dp,0x3f,sizeof(dp));
		dp[1][0]=0;
		for(int mask=1;mask<1<<V.size();mask++) {
			FOR(x,V.size()) if(mask & (1<<x)) {
				FOR(y,V.size()) if(x!=y && (mask & (1<<y))) dp[mask][x] = min(dp[mask][x], dp[mask^(1<<x)][y]+mat[V[x]][V[y]]);
			}
		}
		
		int ok=0;
		FOR(j,V.size()) if(dp[(1<<V.size())-1][j]<=K) ok++;
		if(ok==0) V.pop_back();
		else ret += (1LL<<i)-1;
	}
	
	cout << ret << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
