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

ll dp[1<<20];
const ll mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
int X,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>K;
	
	dp[0]=1;
	ll a=X*modpow(100)%mo;
	ll b=(100-X)*modpow(100)%mo;
	int mask;
	FOR(i,2*K) {
		int mask;
		FOR(mask,1<<i) {
			dp[mask|(1<<i)]=dp[mask]*a%mo;
			dp[mask]=dp[mask]*b%mo;
		}
	}
	
	ll ret=0;
	FOR(mask,1<<(2*K)) {
		int cur=0;
		int d=0;
		FOR(i,2*K) {
			if(mask&(1<<i)) cur++;
			else cur--;
			if(cur<0) break;
			d=max(d,cur);
			
		}
		if(cur==0) (ret+=d*dp[mask])%=mo;
			
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
