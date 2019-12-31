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

int T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	int sc[]={4,7,17,22};
	
	cin>>T;
	while(T--) {
		x=y=0;
		cin>>i;
		while(i--) cin>>s, x+=sc[s[0]-'A'];
		cin>>i;
		while(i--) cin>>s, y+=sc[s[0]-'A'];
		
		if(x>y) _P("WIN\n");
		if(x<y) _P("LOSE\n");
		if(x==y) _P("DOTEN\n");
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
