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
ll M[200][200];
int dist[105][105][4];
int dd[4]={1,0,-1,0};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H;
	FOR(y,H) FOR(x,W) cin>>M[y][x];
	
	FOR(y,H) FOR(x,W) FOR(i,4) dist[y][x][i]=100000;
	dist[0][1][0]=1;
	dist[1][0][1]=1;
	queue<int> Q;
	Q.push(0*1000+1*10+0);
	Q.push(1*1000+0*10+1);
	while(Q.size()) {
		int k=Q.front();
		Q.pop();
		int cy=k/1000, cx=k/10%100, d=k%10;
		int cy2=cy-dd[d^1],cx2=cx-dd[d];
		FOR(i,4) {
			int ty=cy+dd[i^1];
			int tx=cx+dd[i];
			if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
			if(dist[ty][tx][i]<=dist[cy][cx][d]+1) continue;
			if(M[cy2][cx2]==M[ty][tx]) continue;
			if((M[cy2][cx2]-M[cy][cx])*(M[ty][tx]-M[cy][cx])<=0) continue;
			dist[ty][tx][i]=dist[cy][cx][d]+1;
			Q.push(ty*1000+tx*10+i);
		}
	}
	
	int mi=100000;
	FOR(i,4) mi=min(mi,dist[H-1][W-1][i]);
	if(mi>=100000) mi=-1;
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
