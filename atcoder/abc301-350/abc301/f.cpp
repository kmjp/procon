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


ll dp[402020][3];
int C[402020][53];
const ll mo=998244353;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
string S;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	cin>>S;
	int N=S.size();
	reverse(ALL(S));
	FOR(i,N) {
		FOR(j,53) {
			C[i+1][j]=C[i][j];
		}
		if(S[i]>='a'&&S[i]<='z') x=S[i]-'a';
		if(S[i]>='A'&&S[i]<='Z') x=S[i]-'A'+26;
		if(S[i]=='?') x=52;
		C[i+1][x]++;
		S[i]=x;
	}
	ll ng=0;
	dp[0][0]=1;
	FOR(i,N) {
		ll a=0;
		FOR(j,52) if(S[i]==j||S[i]==52) {
			if(j>=26&&j<52) {
				(dp[i+1][1]+=dp[i][0])%=mo;
				(dp[i+1][1]+=dp[i][1])%=mo;
			}
			if(j>=0&&j<26) {
				a+=dp[i][1];
				(dp[i+1][0]+=dp[i][0])%=mo;
			}
		}
		a%=mo;
		x=y=0;
		FOR(j,26) {
			k=C[N][26+j]-C[i+1][26+j];
			if(k>=2) x++;
			if(k==1) y++;
		}
		int pat=C[N][52]-C[i+1][52];
		if(x) {
			(ng+=modpow(52,pat)*a)%=mo;
		}
		else {
			int ok=26-x-y;
			ll num=0;
			ll w=modpow(52,pat);
			for(j=0;j<=min(pat,ok);j++) {
				w-=comb(pat,j)*comb(ok,j)%mo*fact[j]%mo*modpow(26,pat-j)%mo;
			}
			w=(w%mo+mo)%mo;
			(ng+=w*a)%=mo;
		}
	}
	ll a=modpow(52,C[N][52]);
	cout<<(a-ng+mo)%mo<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
