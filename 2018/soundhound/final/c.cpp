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
ll mo=1000000007;
ll dp[31][31][31];
const int CN=41;
ll C[CN][CN];
ll p2[1010];


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
	p2[0]=1;
	FOR(i,1000) p2[i+1]=p2[i]*2%mo;
	
	cin>>N>>D;
	dp[1][N-2][1]=1;
	for(i=2;i<=D;i++) {
		for(int left=1;left<=N-2;left++) {
			for(int pre=1;pre<=N-2;pre++) if(dp[i-1][left][pre]) {
				for(x=1;x<=left;x++) (dp[i][left-x][x]+=dp[i-1][left][pre]*C[left][x]%mo*p2[x*(x-1)/2]%mo*modpow(p2[pre]+mo-1,x))%=mo;
			}
		}
	}
	ll ret=0;
	for(int left=0;left<=N-1;left++) {
		for(x=1;x<=N-1;x++) if(dp[D][left][x]) {
			(ret+=dp[D][left][x]*(p2[x]+mo-1)%mo*modpow(p2[x+1],left)%mo*p2[left*(left-1)/2])%=mo;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
