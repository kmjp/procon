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

int N,K;
int A[202020];
const ll mo=1000000007;

ll fact[202020];
ll factr[202020];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

//ll hcomb(int P_,int Q_) { return comb(P_+Q_-1,Q_);}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	fact[0]=factr[0]=1;
	FOR(i,N+1) {
		fact[i+1]=fact[i]*(K+i+1)%mo;
		factr[i+1]=factr[i]*(i+1)%mo;
	}
	
	
	
	ll ret=0;
	FOR(i,N) {
		cin>>A[i];
		int L=i+1;
		int R=N-i;
		ret+=fact[L-1]*fact[R-1]%mo*modpow(factr[L-1]*factr[R-1]%mo)%mo*A[i]%mo;
		
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
