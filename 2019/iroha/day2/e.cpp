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
ll mo=1000000007;

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
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll ret=comb(N-1+M-1,M-1);
	
	for(int a2=0;a2<=M;a2++) {
		int a1=N-a2*2;
		int a0=M-a1-a2;
		if(a0<0 || a0>M) continue;
		if(a1<0 || a1>M) continue;
		
		if(a1) {
			ret+=mo-comb(M-1,a1-1)*comb(M-a1,a2)%mo;
		}
		if(a2) {
			ret+=mo-comb(M-1,a2-1)*comb(M-a2,a0)%mo;
		}
		
		
	}
	
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
