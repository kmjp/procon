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

int N,T;
int A[51];
int dp[51][100100];
string S;

void dfs(int cur,int v) {
	if(v>T) return;
	if(cur==N) {
		if(v==T) {
			cout << S <<endl;
			exit(0);
		}
		return;
	}
	if(dp[cur][v]) return;
	dp[cur][v] = 1;
	
	S+='+';
	dfs(cur+1,v+A[cur]);
	S.erase(S.size()-1);
	S+='*';
	dfs(cur+1,v*A[cur]);
	S.erase(S.size()-1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N) cin>>A[i];
	
	dfs(1,A[0]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
