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

int D,N;
int T[202];
int A[202],B[202],C[202];
int dp[202][202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>N;
	FOR(i,D) cin>>T[i];
	FOR(i,N) cin>>A[i]>>B[i]>>C[i];
	
	FOR(x,202) FOR(y,202) dp[x][y]=-100000;
	FOR(i,N) if(A[i]<=T[0] && T[0]<=B[i]) dp[1][C[i]]=0;
	
	for(i=1;i<D;i++) {
		FOR(x,N) if(A[x]<=T[i] && T[i]<=B[x]) {
			FOR(y,101) dp[i+1][C[x]]=max(dp[i+1][C[x]],dp[i][y]+abs(y-C[x]));
		}
	}
	
	int ret=0;
	FOR(y,101) ret=max(ret,dp[D][y]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
