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

int M,N;
int C[21];

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];

int dp[101010];


void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>M>>N;
	FOR(i,N) cin>>C[i];
	sort(C,C+N);
	
	memset(dp,0xec,sizeof(dp));
	dp[0]=0;
	FOR(i,N) for(x=0;x+C[i]<=M;x++) dp[x+C[i]] = max(dp[x+C[i]],dp[x]+1);
	
	int ma=0;
	FOR(i,M+1) ma=max(ma,dp[i]);
	for(i=1;i<=M-2;i++) if(divp[M-i]==0 && dp[i]>0) ma += dp[i];
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
