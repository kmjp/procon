#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int B,W,re;
ll mo=1000000007;

ll comb(ll N_, ll C_) {
	const int NUM_=1400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll ret[202020],ret2[202020];

ll E[202020][3];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>B>>W;
	
	for(i=0;i<W;i++) {
		ll pat=modpow(modpow(2,(i+B)))*comb(i+B-1,B-1)%mo;
		E[i+B][0]=pat;
	}
	for(i=0;i<B;i++) {
		ll pat=modpow(modpow(2,(i+W)))*comb(i+W-1,W-1)%mo;
		E[i+W][1]=pat;
		ret2[i+W+1]=pat;
		
	}
	
	ll R[2]={};
	ll pat=1;
	for(i=1;i<=B+W;i++) {
		(E[i][2]=1+(mo-R[0])+(mo-R[1]))%=mo;
		(R[0]+=E[i][0])%=mo;
		(R[1]+=E[i][1])%=mo;
		
		(ret2[i]+=ret2[i-1])%=mo;
		(ret[i]+=modpow(2)*E[i][2]+ret2[i])%=mo;
		cout<<ret[i]<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
