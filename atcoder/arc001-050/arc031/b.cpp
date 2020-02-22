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

string S[10];

bool okok(int sy,int sx) {
	int vis[10][10];
	int y,x;
	
	ZERO(vis);
	FOR(y,10) FOR(x,10) if(S[y][x]=='x') vis[y][x]=1;
	vis[sy][sx]=1;
	
	queue<int> Q;
	Q.push(sy*10+sx);
	while(Q.size()) {
		int k=Q.front();
		Q.pop();
		
		int cy=k/10,cx=k%10,i;
		FOR(i,4) {
			int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
			int ty=cy+dy[i],tx=cx+dx[i];
			if(tx<0 || tx>=10 || ty<0 || ty>=10) continue;
			if(vis[ty][tx]) continue;
			vis[ty][tx]=1;
			Q.push(ty*10+tx);
		}
	}
	
	FOR(y,10) FOR(x,10) if(vis[y][x]==0) return false;
	return true;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,10) cin>>S[y];
	
	FOR(y,10) FOR(x,10) if(okok(x,y)) return _P("YES\n");
	_P("NO\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
