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
int M2,M5;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll g=__gcd(N,M);
	N/=g;
	M/=g;
	if(N%M==0) {
		N/=M;
		while(N%10==0) N/=10;
		return _P("%lld\n",N%10);
	}
	N%=M;
	
	while(M%2==0) M2++, M/=2;
	while(M%5==0) M5++, M/=5;
	if(M!=1) return _P("-1\n");
	
	while(M2<M5) {
		M2++;
		N*=2;
		N%=1000000000;
		while(N%10==0) N/=10;
	}
	while(M2>M5) {
		M5++;
		N*=5;
		N%=1000000000;
		while(N%10==0) N/=10;
	}
	_P("%lld\n",N%10);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
