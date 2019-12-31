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

int H,W,Q;
int DH[20][20];
int DV[20][20];
ll mat[400][400];


int ask(int sy,int sx,int ty,int tx) {
	int i;
	_P("%d %d %d %d\n",sy+1,sx+1,ty+1,tx+1);
	fflush(stdout);
	scanf("%d",&i);
	return i;
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(x,400) FOR(y,400) mat[x][y]=1LL<<60;
	FOR(x,400) mat[x][x]=0;
	
	scanf("%d%d%d",&H,&W,&Q);
	FOR(y,H) FOR(x,W) {
		if(y==0 && x==0) ask(0,0,0,0);
		else if(y==0) mat[y*20+x-1][y*20+x]=mat[y*20+x][y*20+x-1]=ask(y,x,y,x-1);
		else if(x==0) mat[(y-1)*20+x][y*20+x]=mat[y*20+x][(y-1)*20+x]=ask(y,x,y-1,x);
		else {
			r=ask(y-1,x-1,y,x);
			mat[(y-1)*20+x][y*20+x]=mat[y*20+x][(y-1)*20+x]=r-mat[(y-1)*20+(x-1)][(y-1)*20+x];
			mat[y*20+(x-1)][y*20+x]=mat[y*20+x][y*20+(x-1)]=r-mat[(y-1)*20+(x-1)][y*20+(x-1)];
		}
	}
	FOR(i,400) FOR(x,400) FOR(y,400) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
	
	FOR(i,Q) {
		int sy,sx,ty,tx;
		scanf("%d%d%d%d",&sy,&sx,&ty,&tx);
		sy--,sx--,ty--,tx--;
		_P("%d\n",mat[sy*20+sx][ty*20+tx]);
		fflush(stdout);
	}
}


int main(int argc,char** argv){
	solve(); return 0;
}
