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

typedef signed long long s64;
typedef unsigned long long u64;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
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
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N;
s64 C[10001][10];
s64 mo=1000000007LL;
int po[100][100];
int g[100][100];
int vis[100][100];

int search(int sx,int sy,int dx,int dy) {
	//tx,tyから
	int i=0,tx,ty,c=0;
	
	while(1) {
		tx = sx+dx*i;
		ty = sy+dy*i;
		if(tx<0 || ty<0 || tx>=100 || ty>=100) break;
		c+=po[tx][ty];
		vis[tx][ty]=1;
		i++;
	}
	return c;
}

void solve() {
	s64 res;
	int f,r,i,x,y,n,m,v1,v2;
	
	//combination
	ZERO(C);
	C[0][0]=1;
	for(n=1;n<10001;n++) {
		C[n][0]=1;
		for(m=1;m<10;m++) C[n][m]=(C[n-1][m-1]+C[n-1][m])%mo;
	}
	
	//最大公約数を求める
	ZERO(g);
	FOR(y,100){
		FOR(x,y+1) FOR(i,x) if(y%(i+1)==0 && x%(i+1)==0) g[y][x]=g[x][y]=i+1;
	}
	for(y=1;y<100;y++) g[y][0]=g[0][y]=y;
		
	ZERO(po);
	N=GETi();
	FOR(i,N){
		x=GETi();
		y=GETi();
		po[x][y]=1;
	}
	
	//全体から4つ選択
	res = C[N][4];
	//縦方向
	FOR(x,100) {
		int vc=0;
		FOR(y,100) vc+=po[x][y];
		//一直線上の３点とそれ以外を使うケースを引く
		if(vc>=4) res -= C[vc][4];
		if(vc>=3) res -= C[vc][3]*(N-vc);
		res = ((res%mo)+mo)%mo;
	}
	
	//斜め
	int dx,dy,tx,ty;
	for(dx=1;dx<51;dx++) {
		for(dy=-50;dy<51;dy++) {
			if(g[abs(dx)][abs(dy)]!=1) continue;
			ZERO(vis);
			FOR(tx,100) {
				if(tx+dx>=100) continue;
				
				FOR(ty,100) {
					if(vis[tx][ty]==0 && po[tx][ty]) {
						int vc = search(tx,ty,dx,dy);
						if(vc>=4) res -= C[vc][4];
						if(vc>=3) res -= C[vc][3]*(N-vc);
						
					}
				}
			}
			res = ((res%mo)+mo)%mo;
		}
	}
	
	
	_P("%lld\n",res);
	
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&ts,NULL);
	
	init();
	solve();
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



