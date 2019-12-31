#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) { printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__); }
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
ll GETi() { ll i;scanf("%lld",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int H,W,L;
char msg[101];
char str[101][101];
int cost[2][101][101][4];
int la=99999999;
void solve() {
	int x,y,i,j,rr,TM,nc;
	int tx,ty;
	ll p;
	
	GET3(&H,&W,&L);
	ZERO(str);
	GETs(msg);
	FOR(y,H) GETs(str[y]);
	
	if(L<=1) {
		if(H==1 && W==1) {
			_P("-1\n");
		}
		else {
			FOR(y,H) FOR(x,W) {
				if(str[y][x]==msg[0]) {
					_P("1\n");
					return;
				}
			}
		}
		_P("-1\n");
		return;
	}
	
	ZERO(cost);
	FOR(y,H) FOR(x,W) {
		if(str[y][x]==msg[0]) {
			cost[0][y][x][0]=1;
			cost[0][y][x][1]=1;
			cost[0][y][x][2]=1;
			cost[0][y][x][3]=1;
			if(x==0) cost[0][y][x][0]=la;
			if(x==W-1) cost[0][y][x][1]=la;
			if(y==H-1) cost[0][y][x][2]=la;
			if(y==0) cost[0][y][x][3]=la;
		}
		else {
			cost[0][y][x][0]=la;
			cost[0][y][x][1]=la;
			cost[0][y][x][2]=la;
			cost[0][y][x][3]=la;
		}
	}
	
	for(nc=0;nc<L-1;nc++) {
		FOR(y,H) FOR(x,W) {
			FOR(i,4) cost[1-nc%2][y][x][i]=la;
		}
		
		FOR(y,H) FOR(x,W) {
			if(str[y][x]!=msg[nc]) continue;
			//0-¨
			for(tx=x+1;tx<W;tx++) {
				if(str[y][tx]!=msg[nc+1]) continue;
				cost[1-nc%2][y][tx][0] = min(cost[1-nc%2][y][tx][0], cost[nc%2][y][x][1]+tx-x);
				cost[1-nc%2][y][tx][0] = min(cost[1-nc%2][y][tx][0], cost[nc%2][y][x][2]+tx-x);
				cost[1-nc%2][y][tx][0] = min(cost[1-nc%2][y][tx][0], cost[nc%2][y][x][3]+tx-x);
				break;
			}
			//1-©
			for(tx=x-1;tx>=0;tx--) {
				if(str[y][tx]!=msg[nc+1]) continue;
				cost[1-nc%2][y][tx][1] = min(cost[1-nc%2][y][tx][1], cost[nc%2][y][x][0]+x-tx);
				cost[1-nc%2][y][tx][1] = min(cost[1-nc%2][y][tx][1], cost[nc%2][y][x][2]+x-tx);
				cost[1-nc%2][y][tx][1] = min(cost[1-nc%2][y][tx][1], cost[nc%2][y][x][3]+x-tx);
				break;
			}
			//2-ª
			for(ty=y-1;ty>=0;ty--) {
				if(str[ty][x]!=msg[nc+1]) continue;
				cost[1-nc%2][ty][x][2] = min(cost[1-nc%2][ty][x][2], cost[nc%2][y][x][0]+y-ty);
				cost[1-nc%2][ty][x][2] = min(cost[1-nc%2][ty][x][2], cost[nc%2][y][x][1]+y-ty);
				cost[1-nc%2][ty][x][2] = min(cost[1-nc%2][ty][x][2], cost[nc%2][y][x][3]+y-ty);
				break;
			}
			//3-‰º
			for(ty=y+1;ty<H;ty++) {
				if(str[ty][x]!=msg[nc+1]) continue;
				cost[1-nc%2][ty][x][3] = min(cost[1-nc%2][ty][x][3], cost[nc%2][y][x][0]+ty-y);
				cost[1-nc%2][ty][x][3] = min(cost[1-nc%2][ty][x][3], cost[nc%2][y][x][1]+ty-y);
				cost[1-nc%2][ty][x][3] = min(cost[1-nc%2][ty][x][3], cost[nc%2][y][x][2]+ty-y);
				break;
			}
		}
		
	}
	
	int res=la;
	FOR(y,H) FOR(x,W) FOR(i,4) res = min(res, cost[(L-1)%2][y][x][i]);
	
	if(res>=la) res=-1;
	_P("%d\n",res);
	return;
}

int main(int argc,char** argv){
	long long span;
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&start,NULL);
	solve();
	gettimeofday(&end,NULL);
	
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}


