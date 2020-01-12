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

int N;
int X[101010];
const ll mo=1000000007;

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll sum[101010];


ll comb(ll N_, ll C_) {
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
	
	comb(1,1);
	cin>>N;
	FOR(i,N) cin>>X[i];
	
	for(i=1;i<=N;i++) {
		sum[i]=(sum[i-1]+inv[i]*inv[i+1])%mo;
	}
	
	ll ret=0;
	y=N-1;
	FOR(x,y) {
		(ret+=inv[y-x]%mo*(X[y]-X[x]))%=mo;
	}
	
	FOR(x,N-1) {
		if(x) (ret+=X[x]*sum[x])%=mo;
		ret+=mo-X[x]*sum[N-2-x]%mo;
	}
	
	ret=(ret%mo+mo)%mo;
	
	cout<<ret*fact[N-1]%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
