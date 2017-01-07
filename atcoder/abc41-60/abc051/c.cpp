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

int SX,SY,TX,TY;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>SX>>SY>>TX>>TY;
	FOR(i,TX-SX) _P("R");
	FOR(i,TY-SY) _P("U");
	FOR(i,TX-SX) _P("L");
	FOR(i,TY-SY) _P("D");
	_P("D");
	FOR(i,TX-SX+1) _P("R");
	FOR(i,TY-SY+1) _P("U");
	_P("L");
	_P("U");
	FOR(i,TX-SX+1) _P("L");
	FOR(i,TY-SY+1) _P("D");
	_P("R");
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
