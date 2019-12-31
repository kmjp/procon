#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
ll A[404],G[404],dp[404][404];
ll mo=1000000007;

const int CN=1001;
ll C[CN][CN];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
	
	cin>>N>>K;
	G[0]=1;
	FOR(i,N+1) for(j=K;j<=N-i;j++) (G[i+j] += G[i]*C[i+j-1][j-1])%=mo;
	
	dp[0][0]=1;
	FOR(i,N+1) FOR(j,i+1) for(k=0;i+k+1<=N;k++)
		(dp[i+k+1][j+1]+=dp[i][j]*G[k])%=mo;
	
	A[0]=1;
	for(i=1;i<=N;i++) {
		A[i]=G[i];
		for(j=1;j<i;j++) A[i] -= dp[i][j]*A[j]%mo;
		A[i]=((A[i]%mo)+mo)%mo;
	}
	cout<<A[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
