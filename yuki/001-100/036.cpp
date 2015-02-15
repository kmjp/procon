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

ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N==1) return _P("NO\n");
	ll t;
	for(t=2;t*t<=N;t++) {
		if(N%t==0) break;
	}
	if(t*t>N) return _P("NO\n");
	N/=t;
	for(t=2;t*t<=N;t++) {
		if(N%t==0) return _P("YES\n");
	}
	_P("NO\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
