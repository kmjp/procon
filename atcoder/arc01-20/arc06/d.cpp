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

int H,W;
char line[2000][2000];

int mm[3];
char pat[3][8][8] ={
	{
		".......",
		"...o...",
		"..o.o..",
		".o...o.",
		".ooooo.",
		".o...o.",
		".......",
	},
	{
		".......",
		".oooo..",
		".o...o.",
		".oooo..",
		".o...o.",
		".oooo..",
		".......",
	},
	{
		".......",
		"..ooo..",
		".o...o.",
		".o.....",
		".o...o.",
		"..ooo..",
		".......",
	},
};
char rpat[3][4][8][8];
int rpat_dx[3][4];
int rpat_dy[3][4];

int match(int ty,int tx,int pat,int rot,int size) {
	int sy,sx,y,x,mx,my;
	
	sx = tx - size*rpat_dx[pat][rot];
	sy = ty - size*rpat_dy[pat][rot];
	
	
	if(sy<0 || sx < 0) return 0;
	if(sy+7*size>H || sx+7*size>W) return 0;
	
	
	for(y=sy;y<sy+size*7;y++) {
		for(x=sx;x<sx+size*7;x++) {
			my = (y-sy)/size;
			mx = (x-sx)/size;
			if(line[y][x] != rpat[pat][rot][my][mx]) return 0;
		}
	}
	
	for(y=sy;y<sy+size*7;y++) {
		for(x=sx;x<sx+size*7;x++) {
			line[y][x]='.';
		}
	}
	return 1;
	
}


void search(int tx,int ty) {
	int size=1;
	int y,x,p,rr;
	
	
	while(1) {
		if(size*7 > H || size*7>W) {
			_P("error : %d %d %d\n",ty,tx,size);
			exit(0);
		}
		
		FOR(p,3) {
			FOR(rr,4) {
				if(match(ty,tx,p,rr,size)) {
					mm[p]++;
					return;
				}
			}
		}
		
		size++;
	}
	
	
}


void solve() {
	int x,y,i,p,rr;
	
	
	//rot
	ZERO(rpat);
	ZERO(mm);
	FOR(p,3) {
		FOR(rr,4) {
			rpat_dx[p][rr]=9999;
			rpat_dy[p][rr]=9999;
			
			FOR(y,7) {
				FOR(x,7) {
					if(rr==0) rpat[p][rr][y][x]=pat[p][y][x];
					if(rr==1) rpat[p][rr][y][x]=pat[p][6-y][6-x];
					if(rr==2) rpat[p][rr][y][x]=pat[p][6-x][6-y];
					if(rr==3) rpat[p][rr][y][x]=pat[p][x][y];
					if(rpat[p][rr][y][x]=='o' && rpat_dx[p][rr]==9999) {
						rpat_dx[p][rr]=x;
						rpat_dy[p][rr]=y;
					}
				}
			}
		}
	}
	
	
	GET2(&H,&W);
	FOR(y,H) GETs(line[y]);
	
	FOR(y,H) {
		FOR(x,W) {
			if(line[y][x]=='o') {
				search(x,y);
			}
		}
	}
	
	
	
	_P("%d %d %d\n",mm[0],mm[1],mm[2]);
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



