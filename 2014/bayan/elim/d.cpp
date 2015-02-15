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

ll N,M;
ll mo=1000000007;

ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	if(N>M) swap(N,M);
	
	
	int h=1,w=1;
	ll area=5*N*M;
	ll left=N*M-1;
	ll po=0;
	while(h<N || w<M) {
		if(h==w && h<N) area+=2*left, left-=h, w++, po+=2+(h-1);
		else if(h==w || h==N) area+=2*left, left-=h, w++, po+=1+(h-1);
		else area+=2*left, left-=w, h++, po+=1+(w-1);
	}
	_P("%lld %lld\n",area,modpow(2,po));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	int T;
	cin>>T;
	FOR(i,T) {
		_P("Case #%d:\n",i+1);
		solve();
	}
	return 0;
}
