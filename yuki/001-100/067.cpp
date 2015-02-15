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
ll L[300000],K;


ll num(double v) {
	ll t=0;
	int i;
	FOR(i,N) t+=L[i]/v;
	return t;
}

void solve() {
	int i,j,k,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i];
	cin>>K;
	
	double l=0,r=1e11;
	double m;
	FOR(i,100) {
		m=(l+r)/2;
		if(num(m)>=K) l=m;
		else r=m;
	}
	_P("%.12lf\n",m);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
