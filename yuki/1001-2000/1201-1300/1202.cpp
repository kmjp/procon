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
int S[1010][1010];
const ll mo=1000000007;

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

void solve() {
	
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>S[y][x];
	}
	ll ret=0;
	FOR(y,H) FOR(x,W) {
		//ç≈å„Ç…-1
		ret+=comb(y+x,x)*comb(S[y][x]-1+y+x,y+x)%mo;
		//ç≈å„Ç…èc
		// sum(Comb(0+m,0)Å`comb(n+m,n))=comb(n+m+1,n)Çóòóp
		ll a=comb(S[y][x]-1+x+y+1,S[y][x]-1);
		ll b=comb(S[y+1][x]-1+x+y+1,S[y+1][x]-1);
		(ret+=(a-b)*comb(x+y,x))%=mo;
		ll c=comb(S[y][x+1]-1+x+y+1,S[y][x+1]-1);
		(ret+=(a-c)*comb(x+y,x))%=mo;
	}
	
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
