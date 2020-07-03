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

ll N;
ll mo=1000000007;
const int CN=4001;
ll C[CN][CN];
ll dp[2300];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
	
	cin>>N;
	if(N<=2) return _P("0\n");
	
	dp[0]=dp[1]=dp[2]=1;
	dp[3]=2;
	for(i=3;i<=N-1;i++) for(x=0;x<=i;x+=2) (dp[i+1]+=C[i][x]*dp[x]%mo*dp[i-x])%=mo;
	
	cout<<dp[N]*2%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
