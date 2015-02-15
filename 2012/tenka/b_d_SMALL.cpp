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


int W,H;
char str[20][20];
int B[20];


int dfs(int num, char ts[5][6]) {
	int i,x,y,tx,ty;
	int nb=0,min=9999;
	FOR(y,H) FOR(x,W) if(ts[y][x]=='#') nb++;
	if(nb==0) return num;
	if(nb==1) return num+1;
	
	FOR(y,H) FOR(x,W) {
		if(ts[y][x]=='#') continue;
		//ŽŽ‚·H
		bool ok=false;
		FOR(ty,H) if(ts[ty][x]=='#') ok=true;
		FOR(tx,W) if(ts[y][tx]=='#') ok=true;
		if(ok) {
			char tss[5][6];
			memmove(tss,ts,sizeof(tss));
			FOR(ty,H) tss[ty][x]='.';
			FOR(tx,W) tss[y][tx]='.';
			i = dfs(num+1,tss);
			if(min>i) min=i;
			
		}
	}
	
	return min;
}

void solve() {
	int d,i,j,no,h,m,s,t,k,ne,x,y,min=9999;
	int ns=0,c,p;
	
	H=GETi();
	W=GETi();
	FOR(y,H) GETs(str[y]);
	
	if(H<=5 && W<=5) {
		char tstr[5][6];
		FOR(i,5) strcpy(tstr[i],str[i]);
		min = dfs(0,tstr);
	}
	if(min==9999) min=-1;
	_P("%d\n",min);
	
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



