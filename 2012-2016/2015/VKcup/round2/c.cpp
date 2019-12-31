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

int X[2],Y[2],T[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X[0]>>Y[0]>>X[1]>>Y[1];
	
	if(X[0]<=X[1]&&Y[0]<=Y[1]) return _P("Polycarp\n");
	if(X[0]+Y[0]<=max(X[1],Y[1])) return _P("Polycarp\n");
	return _P("Vasiliy\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
