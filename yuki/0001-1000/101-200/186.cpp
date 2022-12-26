#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll X[1010],Y[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>X[i]>>Y[i];
	ll xx=0,yy;
	for(i=0;i<=Y[1];i++) {
		if(X[0]+Y[0]*i>0 && ((X[0]+Y[0]*i) % Y[1]==X[1])) {
			xx=X[0]+Y[0]*i;
			yy=Y[0]*Y[1]/__gcd(Y[0],Y[1]);
			break;
		}
	}
	if(xx==0) return _P("-1\n");
	for(i=0;i<=Y[2];i++) {
		if(xx+yy*i>0 && ((xx+yy*i) % Y[2]==X[2])) return _P("%lld\n",xx+yy*i);
	}
	return _P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
