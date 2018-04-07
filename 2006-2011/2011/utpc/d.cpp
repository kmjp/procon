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
string S[20];
int memo[20][20][4][16];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

void dfs(int y,int x,int d,int v) {
	int i;
	y=(y+H)%H;
	x=(x+W)%W;
	if(S[y][x]=='@') {
		_P("YES\n");
		exit(0);
	}
	if(memo[y][x][d][v]) return;
	memo[y][x][d][v]=1;
	if(S[y][x]=='?') {
		FOR(i,4) dfs(y+dy[i],x+dx[i],i,v);
		return;
	}
	if(S[y][x]=='<') d=2;
	if(S[y][x]=='^') d=3;
	if(S[y][x]=='>') d=0;
	if(S[y][x]=='v') d=1;
	if(S[y][x]=='_') d=(v==0)?0:2;
	if(S[y][x]=='|') d=(v==0)?1:3;
	if(S[y][x]>='0' && S[y][x]<='9') v=(S[y][x]-'0');
	if(S[y][x]=='+') v=(v+1)%16;
	if(S[y][x]=='-') v=(v+15)%16;
	dfs(y+dy[d],x+dx[d],d,v);
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	dfs(0,0,0,0);
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
