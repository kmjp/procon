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

int H,W;
string A,B,C,D;
ll mo=998244353;

ll combi(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll L[101010],R[101010],P[101010],RS[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>A>>B>>C>>D;
	FORR(c,A) c-='0';
	FORR(c,B) c-='0';
	FORR(c,C) c-='0';
	FORR(c,D) c-='0';
	s=A+B+C+D;
	
	if(count(ALL(s),1)==0) return _P("1\n");
	ll ret=0;
	FOR(i,2) {
		ZERO(L);
		ZERO(R);
		ZERO(P);
		ZERO(RS);
		
		int NL=count(ALL(A),1);
		int NR=count(ALL(B),1);
		int NT=0,NB=0;
		P[0]=1;
		FOR(x,W) {
			if(C[x]==0 && D[x]==0) {
				L[x+1]=0;
			}
			else if(NL==0) {
				if(NT+NB==0) L[x+1]=1;
				else L[x+1]=0;
			}
			else {
				L[x+1] = combi(NT+NB+NL-1,NL-1);
			}
			P[x+1]=P[x];
			if(C[x]&&D[x]) P[x+1]=2*P[x]%mo;
			NT+=C[x];
			NB+=D[x];
		}
		NT=0,NB=0;
		for(x=W-1;x>=0;x--) {
			if(C[x]==0 && D[x]==0) {
				R[x+1]=0;
			}
			else if(NR==0) {
				if(NT+NB==0) R[x+1]=1;
				else R[x+1]=0;
			}
			else {
				R[x+1] = combi(NT+NB+NR-1,NR-1);
			}
			(R[x+1]*=P[x+1])%=mo;
			(RS[x+1]=RS[x+2]+R[x+1])%=mo;
			
			(ret += (C[x]+D[x])*L[x+1]*RS[x+1]%mo*modpow(P[x+1]))%=mo;
			
			NT+=C[x];
			NB+=D[x];
		}
		
		
		swap(H,W);
		swap(A,C);
		swap(B,D);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
