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

int W,R,M,S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>R>>M>>S;
	if(M>=10) return _P("NOTHING\n");
	if(W<35 || R<40) return _P("EMERGENCY\n");
	if(R>60) return _P("NIGHTMARE\n");
	if(S>8*60*60) return _P("WAKE-UP\n");
	_P("NOTHING\n");
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
