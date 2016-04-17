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

int D[7];

int isKado(int a,int b,int c) {
	if(a==c) return 0;
	if(a<b && c<b) return 1;
	if(a>b && c>b) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,7) cin>>D[i];
	sort(D,D+7);
	do {
		int ok=1;
		for(i=0;i<=4;i++) ok &= isKado(D[i],D[i+1],D[i+2]) & (D[i]<D[i+2]);
		if(ok) return _P("YES\n");
		
	} while(next_permutation(D,D+7));
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
