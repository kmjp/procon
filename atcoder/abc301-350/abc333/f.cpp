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

const ll mo=998244353;
int N;
ll dp[3030][3030];
ll S[3030];
ll r2[6030];
ll p2[6030];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll rev2=(mo+1)/2;
	r2[0]=p2[0]=1;
	FOR(i,6010) {
		r2[i+1]=r2[i]*rev2%mo;
		p2[i+1]=p2[i]*2%mo;
	}
	
	cin>>N;
	
	dp[1][0]=1;
	for(i=2;i<=N;i++) {
		FOR(x,i-1) {
			S[x+1]=(S[x]+dp[i-1][x]*p2[x])%mo;
		}
		ll p=modpow(1+mo-r2[i]);
		FOR(x,i) {
			ll sum=(S[x]*r2[x]+(S[i-1]+mo-S[x])*r2[i+x])%mo;
			dp[i][x]=sum%mo*p%mo;
		}
		
	}
	
	FOR(i,N) cout<<dp[N][i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
