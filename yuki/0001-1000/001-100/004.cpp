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

int N;
int W[101];
int dp[100001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	dp[0]=1;
	y=0;
	FOR(i,N) {
		cin>>x;
		for(j=10000;j>=0;j--) dp[j+x] |= dp[j];
		y+=x;
	}
	if(y%2==0 && dp[y/2]) _P("possible\n");
	else _P("impossible\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
