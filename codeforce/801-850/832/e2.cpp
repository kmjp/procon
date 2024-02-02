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

int T,N,M;
const ll mo=1000000007;
const int NUM_=10000007;
static int fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(ll P_,ll Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
int p2[5001000];

void solve() {
	int i,j,k,l,r,x,y; string s;

	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = 1LL*inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=1LL*fact[i-1]*i%mo, factr[i]=1LL*factr[i-1]*inv[i]%mo;
	
	p2[0]=1;
	FOR(i,5000100) p2[i+1]=p2[i]*2%mo;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		
		ll ret=0;
		
		for(i=1;i<=M;i++) {
			//ll a=hcomb(i,M-i);
			ll a=comb(M-1,M-i);
			ll na=1LL*fact[M-1]*fact[N+i-1]%mo*factr[M-i]%mo*factr[i-1]%mo*factr[i]%mo;
			/*
			for(j=0;j<=N;j++) {
				ll b=comb(i+j,j);
				//ll c=hcomb(i+j,N-j);
				ll c=comb(i+N-1,N-j);
				//(ret+=(i+j+1)*a%mo*b%mo*c)%=mo;
				
				//(ret+=fact[M-1]*fact[i+j]%mo*fact[N+i-1]%mo*factr[M-i]%mo*factr[i-1]%mo*factr[i]%mo*factr[j]%mo*factr[i+j-1]%mo*factr[N-j]%mo*(i+j+1))%=mo;
				(ret+=na*(i+j)%mo*(i+j+1)%mo*factr[j]%mo*factr[N-j])%=mo;
			}
			*/
			ll s=((1LL*i*i+i)%mo*p2[N]%mo+1LL*(2*i+1)*N%mo*p2[N-1]%mo+1LL*N*(p2[N-1]+(N>=2?1LL*(N-1)*p2[N-2]%mo:0LL)))%mo;
			s=s*factr[N]%mo;
			ret+=na*s%mo;
		}
		
		
		
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
