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
#else
#define DBG(...)
#define DV(...)
#endif


#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#define _Dm(fmt) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__)
#define _D(fmt, ...) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
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


int R,C,D;
int P[201],V[201];
char field[501][501];
int RW[501][501];
int CW[501][501];
int maxv;

int test(int x,int y,int K){
	int sum[3][3];
	int tx,ty,ix,iy,sx,sy;
	ZERO(sum);
	
	sx=sy=0;
	if(K%2==0) {
		//行の処理
		for(ty=y;ty<y+K;ty++) {
			if(ty==y || ty==y+K-1) sy += (RW[ty][x+K-1]-RW[ty][x+1]) * (ty*2 - (y*2+(K-1)));
			else sy += (RW[ty][x+K]-RW[ty][x]) * (ty*2 - (y*2+(K-1)));
		}
		//列
		for(tx=x;tx<x+K;tx++) {
			if(tx==x || tx==x+K-1) sx += (CW[tx][y+K-1]-CW[tx][y+1]) * (tx*2 - (x*2+(K-1)));
			else sx += (CW[tx][y+K]-CW[tx][y]) * (tx*2 - (x*2+(K-1)));
		}
	}
	else {
		//行の処理
		for(ty=y;ty<y+K;ty++) {
			if(ty==y || ty==y+K-1) sy += (RW[ty][x+K-1]-RW[ty][x+1]) * (ty - (y+K/2));
			else sy += (RW[ty][x+K]-RW[ty][x]) * (ty - (y+K/2));
		}
		//列
		for(tx=x;tx<x+K;tx++) {
			if(tx==x || tx==x+K-1) sx += (CW[tx][y+K-1]-CW[tx][y+1]) * (tx - (x+K/2));
			else sx += (CW[tx][y+K]-CW[tx][y]) * (tx - (x+K/2));
		}
	}
	
	if(sx==0 && sy==0) return 1;
	return 0;
}


int check(int K) {
	int x,y;
	
	//左上のポイントを探す
	for(y=0;y<=R-K;y++) {
		for(x=0;x<=C-K;x++) {
			if(test(x,y,K))
				return 1;
		}
	}
	return 0;
}


void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	double br,tb1,tb2,start,end;
	char list[1000],ts[2],ress[1000];
	int prep,maxv,st,ed,sv;;
	long long s,t,p;
	
	ZERO(field);
	ZERO(V);
	GET3(&R,&C,&D);
	
	FOR(i,R) {
		GETs(field[i]);
		//_P("%s\n",field[i]);
	}
	ZERO(RW);
	ZERO(CW);
	//各行の重さ
	FOR(y,R) {
		RW[y][0]=0;
		FOR(x,C) {
			RW[y][x+1]=RW[y][x]+field[y][x]-'0';
		}
	}
	//各列の重さ
	FOR(x,C) {
		CW[x][0]=0;
		FOR(y,R) {
			CW[x][y+1]=CW[x][y]+field[y][x]-'0';
		}
	}
	
	k=R;
	if(k>C) k=C;
	for(;k>=3;k--) if(check(k)) break;
	}
	
	if(k<3) {
		_PE("Case #%d: IMPOSSIBLE\n",_loop);
	}
	else {
		_PE("Case #%d: %d\n",_loop, k);
	}
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
	
	GET1(&loops);
	gets(tmpline);
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL);
		solve(loop);
		gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		_E("                                     time: %lld ms\n",span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



