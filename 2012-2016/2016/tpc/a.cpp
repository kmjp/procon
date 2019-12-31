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
string S[303];
int dist[2][303][303];
int sy,sx,gy,gx;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) {
		dist[0][y][x]=dist[1][y][x]=101010;
		if(S[y][x]=='S') sy=y,sx=x,S[y][x]='.';
		if(S[y][x]=='G') gy=y,gx=x,S[y][x]='.';
	}
	
	queue<int> Q;
	dist[0][sy][sx]=dist[1][gy][gx]=0;
	Q.push(sy*1000+sx);
	Q.push(1000000+gy*1000+gx);
	while(Q.size()) {
		r=Q.front();
		Q.pop();
		int pat=r/1000000;
		int cy=r/1000%1000;
		int cx=r%1000;
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0 || ty>=H || tx<0 || tx>=W || S[ty][tx]=='#') continue;
			if(dist[pat][ty][tx]>dist[pat][cy][cx]+1) {
				dist[pat][ty][tx]=dist[pat][cy][cx]+1;
				Q.push(pat*1000000+ty*1000+tx);
			}
		}
	}
	
	int ma=0;
	FOR(y,H) FOR(x,W) if(S[y][x]=='#') {
		int dd[4]={1,0,-1,0};
		int mi=100000;
		FOR(i,4) FOR(j,4) {
			int cy=y+dd[i];
			int cx=x+dd[i^1];
			int ty=y+dd[j];
			int tx=x+dd[j^1];
			if(cy<0 || cy>=H || cx<0 || cx>=W) continue;
			if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
			mi=min(mi,2+dist[0][cy][cx]+dist[1][ty][tx]);
		}
		if(mi<100000) ma=max(ma,mi);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
