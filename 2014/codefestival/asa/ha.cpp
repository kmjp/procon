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

long double prob(long double p, ll v) {
	if(v==0) return 0;
	if(v==1) return p;
	long double pp=prob(p,v/2);
	
	if(v%2==0) return 2*pp*(1-pp);
	else return 2*pp*(1-pp)*(1-p)+(pp*pp+(1-pp)*(1-pp))*p;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	long double P;
	ll N;
	cin>>P>>N;
	_P("%.12Lf\n",prob(P,N));



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
