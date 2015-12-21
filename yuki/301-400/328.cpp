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

ll C[5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,4) cin>>C[i+1];
	ll X=C[1]*C[3]-C[2]*C[2];
	ll Y=C[1]*C[4]-C[2]*C[3];
	ll Z=C[2]*C[4]-C[3]*C[3];
	
	if(Y*Y-4*X*Z>=0) _P("R\n");
	else _P("I\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
