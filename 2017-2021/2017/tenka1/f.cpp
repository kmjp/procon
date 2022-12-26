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

int Q;
ll A,M;

ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	ll g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

pair<ll,ll> crt(ll a1,ll mo1,ll a2,ll mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	ll g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<ll,ll>(-1,0); // N/A
	__int128_t lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<ll,ll>(-2,0); // overflow
	
	__int128_t v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

ll modpow(ll a, ll n,ll mo) {
	ll r=1; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int phi(int p) {
	int op=p;
	for(int x=2;x*x<=p;x++) if(p%x==0) {
		op=op/x*(x-1);
		while(p%x==0) p/=x;
	}
	if(p>1) op=op/p*(p-1);
	return op;
}

ll hoge(ll A,ll M) {
	if(M==1) return 30;
	if(A==0) return M;
	if(A==1) return 1;
	
	ll mm=phi(M);
	ll mv=hoge(A,mm);
	if(mv==-1) return -1;
	ll v=modpow(A,mv,M);
	auto p=crt(v,M,mv,mm);
	if(p.first<0) return -1;
	
	while(p.first<30) p.first+=p.second;
	return p.first;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>Q;
	while(Q--) {
		cin>>A>>M;
		ll v=hoge(A,M);
		assert(v%M==modpow(A,v,M));
		cout<<v<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
