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
string C[100];
int dist[100][100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H;
	FOR(y,H) cin>>C[y];
	int sy,sx;
	FOR(y,H) FOR(x,W) dist[y][x]=2000;
	FOR(y,H) FOR(x,W) if(C[y][x]=='.') sy=y,sx=x;
	dist[sy][sx]=0;
	queue<int> q;
	q.push(sy*100+sx);
	while(q.size()) {
		int k=q.front();
		q.pop();
		int cy=k/100,cx=k%100;
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=cy+dd[i],tx=cx+dd[i^1];
			if(ty<0 || tx<0 || ty>=H || tx>=W) continue;
			int co=C[ty][tx]=='#';
			if(dist[cy][cx]+co<dist[ty][tx]) {
				dist[ty][tx]=dist[cy][cx]+co;
				q.push(ty*100+tx);
			}
		}
	}
	
	int ma=0;
	FOR(y,H) FOR(x,W) if(C[y][x]=='.') ma=max(ma,dist[y][x]);
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
