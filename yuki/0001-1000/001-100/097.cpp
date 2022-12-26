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

unsigned xor128_x = 123456789, xor128_y = 362436069, xor128_z = 521288629, xor128_w = 88675123;
unsigned xor128() {
	unsigned t = xor128_x ^ (xor128_x << 11);
	xor128_x = xor128_y; xor128_y = xor128_z; xor128_z = xor128_w;
	return xor128_w = xor128_w ^ (xor128_w >> 19) ^ (t ^ (t >> 8));
}

ll mo=100003;
ll N,Q,A[100030];
ll has[100030];

ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		A[i]=xor128()%mo;
		has[A[i]]++;
	}
	
	while(Q--) {
		cin>>x;
		if(x==0) {
			cout<<0<<endl;
			continue;
		}
		
		if(N<=100) {
			y=0;
			FOR(i,N) y=max(y,(int)(A[i]*x%mo));
		}
		else {
			ll rev=modpow(x,mo-2);
			for(y=100002;y>=0;y--) if(has[y*rev%mo]) break;
		}
		cout<<y<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
