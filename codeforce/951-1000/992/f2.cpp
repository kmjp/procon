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
int A,B,C,K;
int D[3030303];
const ll mo=998244353;
const int NUM_=3400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
unordered_map<int,ll> PA,PB,PC,P;

const int prime_max = 4010101;
vector<int> prime;
int NP,divp[prime_max];

const int MA=4202020;
ll tot[MA+1];

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}

void cprime() {
	if(NP) return;
	int i,j;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
	for(i=1;i<=MA;i++) tot[i]=i;
	for(i=2;i<=MA;i++) if(tot[i]==i) {
		for(j=i;j<=MA;j+=i) tot[j]=tot[j]/i*(i-1);
	}
}


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	cprime();
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C>>K;
		int G=0;
		map<int,int> D;
		FOR(i,K) {
			cin>>x;
			D[x]++;
			G=__gcd(G,x);
		}
		PA.clear();
		PB.clear();
		PC.clear();
		FORR(d,enumdiv(A)) PA[d]=tot[A/d];
		FORR(d,enumdiv(B)) PB[d]=tot[B/d];
		FORR(d,enumdiv(C)) PC[d]=tot[C/d];
		
		
		ll sum=0;
		P.clear();
		FORR2(a,aa,PA) FORR2(b,bb,PB) FORR2(c,cc,PC) {
			int a2=A/__gcd(A,a);
			int b2=B/__gcd(B,b);
			int c2=C/__gcd(C,c);
			int d=a2*b2/__gcd(a2,b2);
			int lcm=d*c2/__gcd(d,c2);
			if(G%lcm==0) P[lcm]+=aa*bb*cc;
		}
		
		ll ret=0;
		FORR2(lcm,v,P) {
			int num=A*B*C/lcm;
			ll f=fact[num];
			FORR2(a,b,D) {
				ll f2=modpow(factr[a/lcm],b);
				f=f*f2%mo;
			}
			(ret+=v*f)%=mo;
		}
		cout<<ret*inv[A*B*C]%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
