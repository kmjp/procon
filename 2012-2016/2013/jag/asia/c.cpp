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

int N,M,L,S,T;
int ID[303],R[303];
int mat[303][303];

int dp[1<<17][17];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(1) {
		cin>>N>>M>>L>>S>>T;
		if(N==0) break;
		FOR(x,N) FOR(y,N) mat[x][y]=(x!=y)?10101010:0;
		FOR(i,M) {
			cin>>x>>y>>j;
			mat[x-1][y-1]=mat[y-1][x-1]=j;
		}
		FOR(r,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][r]+mat[r][y]);
		ID[0]=S-1;
		R[0]=T+1;
		FOR(i,L) {
			cin>>ID[i+1]>>R[i+1];
			ID[i+1]--;
		}
		memset(dp,0x3f,sizeof(dp));
		dp[0][0]=0;
		L++;
		int ma=0;
		for(int mask=0;mask<1<<L;mask++) {
			FOR(i,L) FOR(j,L) dp[mask][j]=min(dp[mask][j],dp[mask][i]+mat[ID[i]][ID[j]]);
			FOR(i,L) dp[mask | (1<<i)][i] = min(dp[mask | (1<<i)][i],dp[mask][i] + R[i]);
			if(dp[mask][0]<=T) ma=max(ma,__builtin_popcount(mask));
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
