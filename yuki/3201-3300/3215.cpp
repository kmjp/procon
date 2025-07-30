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

ll dp[202020][11];
ll nv[202020];
const ll mo=998244353;
int T,N,K;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[1][1]=1;
	dp[1][0]=1;
	nv[1]=1;
	for(i=2;i<=200000;i++) {
		nv[i]=(nv[i-1]*2+1)%(mo-1);
		// トップを選択不可
		dp[i][0]=modpow(2,nv[i-1]*2%(mo-1));
		// トップを選択可
		for(x=0;x<=10;x++) for(y=0;x+y<=10;y++) (dp[i][x+y]+=dp[i-1][x]*dp[i-1][y])%=mo;
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		cout<<dp[N][K-1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
