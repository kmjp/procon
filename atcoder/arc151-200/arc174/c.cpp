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
ll memo[1010101];
ll RN;
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	RN=modpow(N);
	for(int n=1;n<=N;n++) {
		ll ret=0;
		//V‹K+V‹K
		if(n>=2) ret+=(n*RN)%mo*((n-1)*RN%mo)%mo*memo[n-2]%mo;
		ret+=(n*RN)%mo*((N-(n-1))*RN%mo)%mo*memo[n-1]%mo;
		ret+=((N-n)*RN)%mo*(n*RN%mo)%mo*(1+memo[n-1])%mo;
		
		if(n<N) {
			ll a=(N-n)*RN%mo;
			a=a*a%mo;
			ret=(a+ret)*modpow(1+mo-a)%mo;
		}
		memo[n]=ret%mo;
	}
	cout<<memo[N]<<" "<<memo[N-1]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
