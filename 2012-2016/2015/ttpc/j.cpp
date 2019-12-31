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

const int NUM_=4001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

int N,K;
ll dp[1010][2];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>K;
	
	dp[0][0]=1;
	for(i=2;i<=N;i++) {
		for(x=2;x<=min(i,K);x++) {
			(dp[i][(x==K)] += dp[i-x][0] * fact[i-1] % mo * factr[i-x]) %= mo ;
			(dp[i][1]      += dp[i-x][1] * fact[i-1] % mo * factr[i-x]) %= mo ;
		}
	}
	cout<<dp[N][1]%mo<<endl;
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
