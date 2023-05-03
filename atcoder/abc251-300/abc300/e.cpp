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

ll N;
const ll mo=998244353;

ll C[10];

ll dp[65][65][65];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(N%2==0) {
		C[2]++;
		N/=2;
	}
	while(N%3==0) {
		C[3]++;
		N/=3;
	}
	while(N%5==0) {
		C[5]++;
		N/=5;
	}
	if(N>1) {
		cout<<0<<endl;
		return;
	}
	
	dp[0][0][0]=1;
	FOR(x,60) FOR(y,60) FOR(k,60) if(dp[x][y][k]) {
		(dp[x+1][y][k]+=dp[x][y][k]*modpow(5))%=mo;
		(dp[x][y+1][k]+=dp[x][y][k]*modpow(5))%=mo;
		(dp[x+2][y][k]+=dp[x][y][k]*modpow(5))%=mo;
		(dp[x][y][k+1]+=dp[x][y][k]*modpow(5))%=mo;
		(dp[x+1][y+1][k]+=dp[x][y][k]*modpow(5))%=mo;
	}
	
	cout<<dp[C[2]][C[3]][C[5]]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
