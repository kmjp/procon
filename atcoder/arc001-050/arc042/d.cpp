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

ll X,A,B,P,XA;
ll mo;
map<ll,int> MM;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>P>>A>>B;
	if(A/(P-1) != B/(P-1)) return _P("1\n");
	A %= (P-1);
	B %= (P-1);
	
	mo=P;
	
	XA=modpow(X,A);
	B-=A;
	
	if(B<=100000000) {
		ll mi=XA;
		FOR(i,B) {
			XA=XA*X%mo;
			mi=min(mi,XA);
		}
		cout<<mi<<endl;
	}
	else {
		
		ll cur=1, sq;
		for(sq=0;sq*sq<=P;sq++) {
			MM[cur]=sq;
			cur=cur*X%P;
		}
		
		ll re=modpow(X),xsq=1;
		FOR(i,sq) xsq=xsq*re%P;
		
		ll XAr=modpow(XA);
		for(ll a=1;a<=P;a++) {
			ll tar=a*XAr%mo;
			ll st=1;
			FOR(i,sq) {
				if(MM.count(tar) && sq*i+MM[tar]<=B) return _P("%lld\n",a);
				tar=tar*xsq%mo;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
