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

int H,W;
char B[101][101];
int BM[101][101];

void dfs(int y,int x,int c) {
	int dx[4]={1,-1,0,0};
	int dy[4]={0,0,1,-1};
	int lo;
	//_P("%d %d %d\n",y,x,BM[y][x]);
	
	BM[y][x]=-1;
	FOR(lo,4) {
		int ty=y+dy[lo];
		int tx=x+dx[lo];
		if(tx<0 || ty<0 || tx>=W || ty>=H) continue;
		if(BM[ty][tx]==c){
			BM[ty][tx]=-1;
			dfs(ty,tx,c);
		}
	}
	
}

void solve() {
	int x,y,i,j,p,rr,TM,TTC;
	
	GET2(&H,&W);
	FOR(y,H) GETs(B[y]);
	FOR(y,H) FOR(x,W) BM[y][x]=B[y][x]-'0';
	
	FOR(y,H) {
		FOR(x,W-2) {
			if(BM[y][x]%10 == BM[y][x+1]%10 && BM[y][x+1]%10 == BM[y][x+2]%10) {
				BM[y][x] = BM[y][x+1] = BM[y][x+2] = 10+(BM[y][x]%10);
			}
		}
	}
	FOR(y,H-2) {
		FOR(x,W) {
			if(BM[y][x]%10 == BM[y+1][x]%10 && BM[y+1][x]%10 == BM[y+2][x]%10) {
				BM[y+2][x] = BM[y+1][x] = BM[y][x] = 10+(BM[y][x]%10);
			}
		}
	}
	rr=0;
	FOR(y,H) {
		FOR(x,W) {
			if(BM[y][x]>=10) {
				rr++;
				dfs(y,x,BM[y][x]);
			}
		}
	}
	
	_P("%d\n",rr);
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

