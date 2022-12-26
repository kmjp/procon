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

int N,X;
ll mo=998244353;
ll comb(ll N_, ll C_) {
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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	int n1,n2;
	ll ret=0;
	
	// S<X
	for(n1=0;n1<=N;n1++) for(n2=0;n1+n2<=N&&n1+n2*2<X;n2++) {
		(ret+=comb(N,n1)*comb(N-n1,n2))%=mo;
	}
	// all 2
	if(X%2) {
		for(n2=0;n2<=N;n2++) if(2*n2>X) (ret+=comb(N,n2))%=mo;
	}
	for(n2=1;n2<=N&&n2*2<X-1;n2++) {
		int lef=X-1-2*n2;
		for(n1=1;n1<=lef;n1++) {
			if((lef-n1)%2) continue;
			int n22=(lef-n1)/2;
			if(n1+n22+2*n2>N) continue;
			(ret+=comb(n1+n22,n22)*comb(N,n1+n22+2*n2))%=mo;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
