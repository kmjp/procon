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
ll mo,X;
ll A[15];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll modlog(ll g,ll a) {  // return g^x=a mod a
	map<ll,ll> M;
	ll cur=1;
	ll sq=sqrt(mo);
	ll i;
	FOR(i,sq) {
		M[cur]=i;
		cur=cur*g%mo;
	}
	
	ll step=cur;
	cur=1;
	ll num=0;
	int lp=0;
	while(1) {
		lp++;
		if(lp>sq+5) return 1LL<<50;
		ll x=a*modpow(cur)%mo;
		if(M.count(x)) return num+M[x];
		cur=cur*step%mo;
		num+=sq;
	}
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>mo;
	FOR(i,N) cin>>A[i];
	cin>>X;

	ll mp=1;
	FOR(i,N) {
		if(mp==X) return _P("%d\n",i);
		mp=mp*A[i]%mo;
		if(mp==X) return _P("%d\n",i+1);
	}
	
	if(mp==1) return _P("Fracture\n");
	
	ll mi=1LL<<50;
	ll mp2=1;
	FOR(i,N) {
		ll a=X*modpow(mp2)%mo;
		
		ll v=modlog(mp,a);
		mi=min(mi,v*N+i);
		
		mp2=mp2*A[i]%mo;
	}
	if(mi>1LL<<45) _P("Fracture\n");
	else cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
