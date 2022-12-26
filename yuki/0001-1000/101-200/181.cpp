#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll A,N,M;

ll modpow(ll a, ll n, ll mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

const int Mmax=2000;
int phi[Mmax+20];

// return min(upbound,A^^B)
ll AtB(ll a,ll b,ll upbound) {
	if(b==0 || a==1) return min(upbound,1LL);
	if(b==1) return min(upbound,a);
	if(b==2) return (a>10)?upbound:min(modpow(a,a,1LL<<60),upbound);
	if(a==2 && b==3) return min(upbound,1LL<<4);
	if(a==3 && b==3) return min(upbound,modpow(3,27,1LL<<60));
	if(a==2 && b==4) return min(upbound,1LL<<16);
	return upbound;
}

ll H4M(ll a,ll b,ll m) {
	if(m==1) return 0;
	if(a==1 || b==0) return 1;
	
	ll t=AtB(a,b-1,m+1);
	if(t<=m) return modpow(a,t,m);
	return modpow(a,m + (H4M(a,b-1,phi[m])-m)%phi[m], m);
}

void GetPhi() {
	int i,x;
	for(x=1;x<=Mmax;x++) for(i=1;i<=x;i++) phi[x]+=__gcd(i,x)==1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>N>>M;
	GetPhi();
	cout<< H4M(A,N,M) << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
