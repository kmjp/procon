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

int N,C;
int A[404],B[404];
ll mo=1000000007;
ll ppow[404][404];
ll ppowS[404][404];
ll dp[404][404];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	ppow[0][0]=1;
	for(i=1;i<=400;i++) {
		ppow[i][0]=1;
		FOR(j,400) ppow[i][j+1]=ppow[i][j]*i%mo;
	}
	FOR(i,401) FOR(j,401)  (ppowS[j+1][i]=ppowS[j][i]+ppow[j][i])%=mo;
	
	
	dp[0][0]=1;
	FOR(i,N) FOR(x,C+1) for(y=0;x+y<=C;y++) {
		ll p=(ppowS[B[i]+1][y]-ppowS[A[i]][y])%mo;
		if(p<0) p+=mo;
		(dp[i+1][x+y] += dp[i][x] * p) %= mo;
	}
	cout<<dp[N][C]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
