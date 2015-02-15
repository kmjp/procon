#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll A[201000],P[201000];
ll T;
ll mo=1000000007;
ll kai[201000];

ll rev(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	N++;
	kai[0]=1;
	FOR(i,N) {
		cin>>A[i];
		kai[i+1]=kai[i]*(i+1)%mo;
	}
	cin>>T;
	if(T<N) return _P("%lld\n",A[T]);
	
	ll a=1;
	FOR(i,N) a=a*(T+mo-i)%mo;
	
	ll ret=0;
	FOR(i,N) {
		ll b=kai[i]*kai[N-1-i]%mo;
		ll rev2=T-i;
		if(rev2<0) rev2+=mo;
		
		if((N-1-i)%2) b=(mo-b)%mo;
		ret += A[i]*a%mo*rev(rev2)%mo*rev(b)%mo;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
