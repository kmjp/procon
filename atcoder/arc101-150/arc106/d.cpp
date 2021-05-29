#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
ll A[202020][305];
ll S[305];
const ll mo=998244353;

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
	
	cin>>N>>K;
	FOR(i,N) {
		A[i][0]=1;
		cin>>A[i][1];
		for(j=2;j<=300;j++) A[i][j]=A[i][j-1]*A[i][1]%mo;
		FOR(j,301) (S[j]+=A[i][j])%=mo;
	}
	
	for(i=1;i<=K;i++) {
		ll ret=0;
		FOR(j,i+1) (ret+=comb(i,j)*S[j]%mo*S[i-j])%=mo;
		ll tmp=S[i];
		FOR(j,i) tmp=2*tmp%mo;
		ret-=tmp;
		ret=(ret%mo+mo)*((mo+1)/2)%mo;
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
