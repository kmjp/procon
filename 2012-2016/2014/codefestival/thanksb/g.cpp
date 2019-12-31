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


int memo[501][501];

int win(int N,int P) {
	int i;
	if(N<=P) return 1;
	if(memo[N][P]==-1) {
		memo[N][P]=0;
		for(i=1;i<=P;i++) {
			if(win(N-i,i+1)==0) memo[N][P]=1;
		}
	}
	return memo[N][P];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	int N,P;
	
	MINUS(memo);
	cin>>N>>P;
	if(win(N,P)) _P("first\n");
	else _P("second\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
