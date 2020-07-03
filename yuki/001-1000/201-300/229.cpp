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

ll T[4],S[3];
ll bo=1LL<<40,si=1;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T[0]>>T[1]>>T[2];
	T[3]=2*T[0]*T[1]*T[2];
	S[0]=T[1]*T[2]*2;
	S[1]=T[0]*T[2]*2;
	S[2]=T[0]*T[1]*2;
	
	FOR(i,4) {
		ll a=S[0]+((i&1)?S[1]:-S[1]);
		ll b=S[0]+((i&2)?S[2]:-S[2]);
		ll bobo=T[3];
		ll sisi=__gcd(a,b);
		ll g=__gcd(sisi,bobo);
		bobo/=g, sisi/=g;
		if(bo*sisi>bobo*si) bo=bobo, si=sisi;
	}
	_P("%lld/%lld\n",bo,si);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
