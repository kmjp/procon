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

int T[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>T[i];
	ll a=T[0]*T[1];
	ll b=T[1]-T[0];
	ll g=__gcd(a,b);
	a/=g;
	b/=g;
	ll c=T[0]*T[2];
	ll d=T[2]-T[0];
	g=__gcd(c,d);
	c/=g;
	d/=g;
	
	a*=d;
	c*=b;
	b*=d;
	a=a/__gcd(a,c)*c;
	g=__gcd(a,b);
	a/=g;
	b/=g;
	_P("%lld/%lld\n",abs(a),abs(b));
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
