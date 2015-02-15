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

int C[256];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,26) cin>>C['a'+i];
	ll ret=1;
	ret*=C['h'];
	ret*=C['e'];
	ret*=C['r'];
	ret*=C['w'];
	ret*=C['d'];
	if(C['o']<2) return _P("0\n");
	if(C['l']<3) return _P("0\n");
	if(ret<=0) return _P("0\n");
	
	int ma=0;
	for(i=1;i<=C['o']-1;i++) ma=max(ma,i*(C['o']-i));
	ret*=ma;
	
	ma=0;
	for(i=2;i<=C['l']-1;i++) ma=max(i*(i-1)*(C['l']-i)/2,ma);
	ret*=ma;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
