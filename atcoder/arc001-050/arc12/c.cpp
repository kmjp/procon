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

int W=19,H=19;
char B[20][20];
int no,nx;

int goal(char c) {
	int x,y;
	
	FOR(y,19) FOR(x,19) {
		if(B[y][x]!=c) continue;
		
		if(x<15 && B[y][x+1]==c && B[y][x+2]==c && B[y][x+3]==c && B[y][x+4]==c) return 1;
		if(y<15 && B[y+1][x]==c && B[y+2][x]==c && B[y+3][x]==c && B[y+4][x]==c) return 1;
		if(x<15 && y<15 && B[y+1][x+1]==c && B[y+2][x+2]==c && B[y+3][x+3]==c && B[y+4][x+4]==c) return 1;
		if(x>=4 && y<15 && B[y+1][x-1]==c && B[y+2][x-2]==c && B[y+3][x-3]==c && B[y+4][x-4]==c) return 1;
	}
	
	return 0;
	
}

void solve() {
	int f,r,i,j,k,l;
	int x,y,mx,my;
	
	no=nx=0;
	FOR(y,19) {
		GETs(B[y]);
		FOR(x,19) {
			if(B[y][x]=='o') no++;
			if(B[y][x]=='x') nx++;
		}
	}
	
	if(no!=nx && no!=nx+1) {
		_P("NO\n");
		return;
	}
	
	char c1 = (no==nx)?'o':'x';
	char c2 = (no==nx)?'x':'o';
	
	if(goal(c1)) {
		_P("NO\n");
		return;
	}
	
	int ng=0;
	FOR(y,19) FOR(x,19) {
		if(B[y][x]==c2) {
			B[y][x]='.';
			if(!goal(c2)) {
				_P("YES\n");
				return;
			}
			ng++;
			B[y][x]=c2;
		}
	}
	
	if(ng) _P("NO\n");
	else _P("YES\n");
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
