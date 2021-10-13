#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dp[10101011][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	dp[0][1]=1;
	for(i=1;i<=N;i++) {
		/*
		// top is 1
		for(x=0;x<=i-1;x++) (dp[i][1]+=(dp[x][1]+dp[x][0])*(dp[i-1-x][1]+dp[i-1-x][0]))%=mo;
		// top is 0
		for(x=0;x<=i;x++) (dp[i][0]+=dp[x][1]*dp[i-x][1])%=mo;
		
		*/
		dp[i][1]+=3*(2*N+1-i)*dp[i-1][1];
		if(i>=2) dp[i][1]+=(4*N+2-i)*dp[i-2][1];
		dp[i][1]=dp[i][1]%mo*modpow(i)%mo;
	}
	cout<<dp[N-1][1]*modpow(N)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
