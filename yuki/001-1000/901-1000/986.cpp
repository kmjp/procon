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
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll p2[303030];
ll fact[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	p2[0]=fact[0]=1;
	FOR(i,301000) {
		p2[i+1]=p2[i]*2%mo;
		fact[i+1]=fact[i]*(i+1)%mo;
	}
	
	cout<<p2[N]<<" ";
	ll ret=modpow(fact[N]);
	FOR(i,N) ret=ret*(p2[M]-p2[i]+mo)%mo;
	cout<<ret<<" ";
	
	ll ret2=1;
	FOR(i,N) ret2=ret2*(p2[N]-p2[i]+mo)%mo;
	(ret2*=modpow(fact[N]))%=mo;
	cout<<(ret*modpow(ret2))%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
