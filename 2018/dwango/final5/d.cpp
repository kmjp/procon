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

int N,M;
string S;
ll mo=1000000007;
const int NUM_=1400001;
ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
ll D[505050],D2[505050];

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll catalan(int n) {
	return fact[2*n]*factr[n]%mo*factr[n+1]%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>S;
	M=N/2;
	
	/*
	D[1]=0;
	D2[1]=1;
	for(i=2;i<=M;i++) {
		for(j=1;j<=i;j++) {
			(D[i]+=catalan(i-j)*D[j-1]+catalan(j-1)*D[i-j]+1LL*j*(i-j)%mo*catalan(j-1)%mo*catalan(i-j))%=mo;
			(D2[i]+=catalan(i-j)*D2[j-1]+catalan(j-1)*D2[i-j]+(2*(j-1)+1+1LL*j*(i-j))%mo*catalan(j-1)%mo*catalan(i-j))%=mo;
		}
	}
	*/
	for(i=2;i<=M;i++) D[i]=(i-1)*catalan(i-1)%mo;
	FOR(i,M+1) (D[i+1]+=4*D[i])%=mo;
	FOR(i,M+1) D2[i]=((catalan(i)*i%mo*i-D[i])%mo+mo)%mo;

	ll Am=(1LL*M*(M-1)/2%mo*catalan(M)+D[M])%mo*fact[M]%mo*fact[M]%mo;
	ll AmpBm=(1LL*M*(M-1)/2%mo*catalan(M)+D2[M])%mo*fact[M]%mo*fact[M]%mo;
	ll Bm=(AmpBm-Am+mo)%mo*((inv[M]*inv[M])%mo)%mo;
	
	ll rev=0,sum=0;
	FORR(c,S) {
		if(c==')') rev++;
		else sum+=rev;
	}
	cout<<(Am+Bm*(sum%mo))%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
