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

int S,E,N,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>s;
	FORR(r,s) {
		if(r=='S') S++;
		if(r=='E') E++;
		if(r=='N') N++;
		if(r=='W') W++;
	}
	
	if(N&&S==0)return _P("No\n");
	if(S&&N==0)return _P("No\n");
	if(E&&W==0)return _P("No\n");
	if(W&&E==0)return _P("No\n");
	_P("Yes\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
