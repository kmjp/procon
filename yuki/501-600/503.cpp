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

ll N,K,D;
ll mo=1000000007;

const int NUM_=2000001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
ll combi(ll N_, ll C_) {
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:combi(P_+Q_-1,Q_);}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>D;
	
	int num=0;
	int M=(N-1)%(K-1)+1;
	int P=(N-1)/(K-1);
	
	if(D==1) {
		cout<<M<<endl;
		return;
	}
	
	ll ret=0;
	ll p=1;
	for(i=0;i<=P;i++) {
		ret += hcomb(M-1,P-i) * p %mo;
		(p*=D)%=mo;
	}
	cout<<ret*M%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
