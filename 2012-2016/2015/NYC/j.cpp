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

ll N,M;
const int CN=5005;
ll C[CN][CN];
ll dp[5005],dp2[5005], p4[5005];
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(x,CN) C[x][0]=C[x][x]=1;
	for(i=1;i<CN;i++) for(j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	
	p4[0]=1;
	FOR(i,5000) p4[i+1]=p4[i]*4%M;
	
	ret = (N+1)*p4[N]%M;
	
	for(i=2;i<=N;i+=2) {
		FOR(j,i+1) if(j%2==0) dp[i] += C[i][j]*C[(i-j)][(i-j)/2]%M*C[j][j/2]%M;
		dp2[i]=((dp[i]%M)+M)%M;
		for(j=2;j<i;j+=2) dp[i] -= dp[i-j]*dp2[j]%M;
		dp[i]=((dp[i]%M)+M)%M;
		ret -= dp[i]*(N-i+1)%M*p4[N-i]%M;
	}
	cout<<(ret%M+M)%M<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
