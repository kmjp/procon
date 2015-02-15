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

int D,A[10005];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D;
	FOR(i,D+1) cin>>A[i];
	for(i=10002;i>=3;i--) if(A[i]) {
		A[i-2]+=A[i];
		A[i]=0;
	}
	if(A[2]) _P("2\n%d %d %d\n",A[0],A[1],A[2]);
	else if(A[1]) _P("1\n%d %d\n",A[0],A[1]);
	else _P("0\n%d\n",A[0]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
