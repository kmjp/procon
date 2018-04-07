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

int A,B;
int H,W;
string S[15];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int vis[16][16][4][16][16];

void dfs(int y,int x,int d,int a,int b) {
	if(S[y][x]=='#') return;
	if(y==H-2&&x==W-2&&a==0 && b==0) {
		_P("Yes\n");
		exit(0);
	}
	if(vis[y][x][d][a][b]) return;
	vis[y][x][d][a][b]=1;
	dfs(y+dy[d],x+dx[d],d,a,b);
	if(a) dfs(y+dy[(d+1)%4],x+dx[(d+1)%4],(d+1)%4,a-1,b);
	if(b) dfs(y+dy[(d+3)%4],x+dx[(d+3)%4],(d+3)%4,a,b-1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	dfs(1,1,0,A,B);
	
	_P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
