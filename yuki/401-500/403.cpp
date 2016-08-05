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

ll A,B,C;
ll mo=1000000007;

ll modpow(ll a, ll n,ll m) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%m,a=a*a%m,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%lld^%lld^%lld",&A,&B,&C);
	A%=mo;
	ll D=modpow(modpow(A,B,mo),C,mo);
	B%=mo-1;
	ll E=modpow(A,modpow(B,C,mo-1) + (mo-1),mo);
	
	cout<<D<<" "<<E<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
