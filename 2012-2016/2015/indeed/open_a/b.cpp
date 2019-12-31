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
string S[1010];
int dist[200][200];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int sy,sx,gy,gx;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='s') S[y][x]='0', sy=y,sx=x;
		FOR(x,W) if(S[y][x]=='t') S[y][x]='0', gy=y,gx=x;
		FOR(x,W) dist[y][x]=10000000;
	}
	dist[sy][sx]=0;
	priority_queue<pair<int,int> > Q;
	Q.push(make_pair(0, sy*1000+sx));
	while(Q.size()) {
		auto r=Q.top();
		Q.pop();
		int cy=r.second/1000, cx=r.second%1000;
		if(-r.first != dist[cy][cx]) continue;
		
		FOR(i,6) {
			int dx[6]={-1,0,-1,1,-1,0}, dy[6]={-1,-1,0,0,1,1};
			int ty=cy+dy[i],tx=cx+dx[i];
			if(dy[i]) tx += cy%2;
			if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
			int co=dist[cy][cx] + S[ty][tx]-'0';
			if(co < dist[ty][tx]) {
				dist[ty][tx] = co;
				Q.push(make_pair(-co, ty*1000+tx));
			}
		}
	}
	cout << dist[gy][gx] << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
