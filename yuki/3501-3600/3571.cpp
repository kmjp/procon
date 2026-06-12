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

int T;
ll N,M;
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		
		// 1—v‘f‚ª0`(M-1)
		ll ret=M%mo*((M-1)%mo)%mo*(mo+1)/2%mo;
		// c‚è(N-1)—v‘f
		(ret*=modpow(M,N-1))%=mo;
		//ƒyƒA‚Æ‚È‚éN-1—v‘f
		(ret*=(N-1)%mo)%=mo;
		//N—v‘f
		(ret*=N%mo)%=mo;
		
		// ˜a‚ªM‚ğ’´‚¦‚½•ªM‚ğˆø‚­
		// (0`(M-1))‚Ì‚Q‚Â‚Ì˜a‚ªM‚ğ’´‚¦‚é‚Ì‚ÍA1+2+...+(M-1)‚ÌM*(M-1)/2’Ê‚è
		ll pat=M%mo*((M-1)%mo)%mo*(mo+1)/2%mo;
		// C(N,2)*modpow(M,N-2)‚ğŠ|‚¯‚é
		(pat*=(N%mo)*((N-1)%mo)%mo*(mo+1)/2%mo)%=mo;
		(pat*=modpow(M,N-1))%=mo;
		
		cout<<(ret+mo-pat)%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
