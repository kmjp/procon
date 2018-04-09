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

int H,W;
string S[505];
int memo[505][505];

int dfs(int y,int x) {
	if(y<0 || y>=H || x<0 || x>=W) return 1;
	if(memo[y][x]==2) return 0;
	if(memo[y][x]>=0) return memo[y][x];
	memo[y][x]=2;
	if(S[y][x]=='D') return memo[y][x]=dfs(y+1,x);
	if(S[y][x]=='U') return memo[y][x]=dfs(y-1,x);
	if(S[y][x]=='L') return memo[y][x]=dfs(y,x-1);
	if(S[y][x]=='R') return memo[y][x]=dfs(y,x+1);
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	int ok=0;
	MINUS(memo);
	FOR(y,H) FOR(x,W) ok+=dfs(y,x);
	cout<<ok<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
