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

int W,H;
int M[101][101];

int okok(int sy,int sx,int dir) {
	int ty=sy,tx=sx,i;
	if(dir==0) tx++;
	if(dir==1) ty++;
	
	int vis[101][101];
	ZERO(vis);
	queue<int> Q;
	Q.push(sy*100+sx);
	vis[sy][sx]=1;
	while(Q.size()) {
		int k=Q.front();
		Q.pop();
		int cy=k/100,cx=k%100;
		if(cy==ty && cx==tx) return 1;
		FOR(i,4) {
			int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
			if(cx==sx&&cy==sy&&i==dir) continue;
			int ttx=cx+dx[i],tty=cy+dy[i];
			if(ttx<0 || ttx>=W || tty<0 || tty>=H) continue;
			if(vis[tty][ttx] || M[tty][ttx]!=M[cy][cx]) continue;
			vis[tty][ttx]=1;
			Q.push(tty*100+ttx);
		}
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H;
	FOR(y,H) FOR(x,W) cin>>M[y][x];
	FOR(y,H) FOR(x,W-1) if(M[y][x]==M[y][x+1] && okok(y,x,0)) return _P("possible\n");
	FOR(y,H-1) FOR(x,W) if(M[y+1][x]==M[y][x] && okok(y,x,1)) return _P("possible\n");
	_P("impossible\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
