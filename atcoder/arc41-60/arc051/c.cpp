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

int N,A,B;
ll V[1010];
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	FOR(i,N) cin>>V[i];
	sort(V,V+N);
	if(A==1) {
		FOR(i,N) cout<<V[i]<<endl;
		return;
	}
	while(B) {
		if(V[0]*A>V[N-1]) break;
		assert(V[0]*A/A ==V[0]);
		V[0]*=A;
		sort(V,V+N);
		B--;
	}
	
	FOR(i,N) {
		if(i>=(B%N)) _P("%lld\n",V[i]%mo * modpow(A,B/N) % mo);
	}
	FOR(i,N) {
		if(i<(B%N)) _P("%lld\n",V[i]%mo * modpow(A,B/N+1) % mo);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
