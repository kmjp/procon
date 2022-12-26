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
string S[1010];

int dist[501][501][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int sx,sy,gy,gx;
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) {
		dist[y][x][0]=dist[y][x][1]=1<<20;
		if(S[y][x]=='S') sy=y,sx=x;
		if(S[y][x]=='G') gy=y,gx=x;
	}
	
	vector<pair<int,int>> V[2];
	V[0] = {{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};
	V[1] = {{1,1},{1,-1},{-1,1},{-1,-1}};
	
	dist[sy][sx][0]=0;
	queue<int> Q;
	Q.push(sy*1000+sx);
	while(Q.size()) {
		k=Q.front();
		Q.pop();
		int ct=k/1000000;
		int cy=k/1000%1000;
		int cx=k%1000;
		
		FORR(r,V[ct]) {
			int ty=cy+r.second;
			int tx=cx+r.first;
			if(tx<0 || ty<0 || ty>=H || tx>=W) continue;
			int tt=ct^(S[ty][tx]=='R');
			if(dist[ty][tx][tt]>dist[cy][cx][ct]+1) {
				dist[ty][tx][tt]=dist[cy][cx][ct]+1;
				Q.push(tt*1000000+ty*1000+tx);
			}
		}
	}
	
	x=min(dist[gy][gx][0],dist[gy][gx][1]);
	if(x>101010) x=-1;
	cout<<x<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
