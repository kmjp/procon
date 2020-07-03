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

int A[14];

void solve() {
	int i,j,k,l,r,x,y; string s;
	FOR(i,5) cin>>x, A[x]++;
	
	int three=0,two=0;
	for(i=1;i<=13;i++) {
		if(A[i]==3) three++;
		if(A[i]==2) two++;
	}
	
	if(three && two) return _P("FULL HOUSE\n");
	if(three) return _P("THREE CARD\n");
	if(two==2) return _P("TWO PAIR\n");
	if(two) return _P("ONE PAIR\n");
	_P("NO HAND\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
