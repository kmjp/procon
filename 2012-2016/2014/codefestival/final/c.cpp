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

ll f(ll v) {
	ll t=0;
	ll vv=1,ov=v;;
	while(v>0) {
		t+=vv*(v%10);
		vv*=ov;
		v/=10;
		if(t>10000000000000000LL) return -1;
	}
	return t;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	ll A,B;
	cin>>A;
	for(B=10;;B++) {
		if(f(B)==A) return _P("%lld\n",B);
		if(f(B)<0) break;
	}
	_P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
