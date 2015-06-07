#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
int vis[501][501];
string S[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int sy,sx,gy,gx;
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='s') sy=y,sx=x,S[y][x]='.';
			if(S[y][x]=='g') gy=y,gx=x,S[y][x]='.';
		}
	}
	
	queue<int> Q;
	Q.push(sy*1000+sx);
	vis[sy][sx]=1;
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop();
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int dy=cy+dd[i];
			int dx=cx+dd[i^1];
			if(dx<0 || dy<0 || dx>=W || dy>=H) continue;
			if(S[dy][dx]=='#' || vis[dy][dx]) continue;
			vis[dy][dx]=1;
			Q.push(dy*1000+dx);
		}
	}
	
	if(vis[gy][gx]) _P("Yes\n");
	else _P("No\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
