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

typedef signed long long ll;
typedef unsigned long long ull;

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

char line[5][5];
int wx,wo;

void chk(char a,char b,char c,char d) {
	int cnt[256];
	ZERO(cnt);
	cnt[a]++;
	cnt[b]++;
	cnt[c]++;
	cnt[d]++;
	
	if(cnt['X']==4 || (cnt['X']==3 && cnt['T']==1)) wx=1;
	if(cnt['O']==4 || (cnt['O']==3 && cnt['T']==1)) wo=1;

}

void solve(int _loop) {
	int i,j,x,y,ne=0;
	
	FOR(y,4) {
		while(1) {
			GETs(line[y]);
			if(strlen(line[y])>=4) break;
		}
		FOR(x,4) if(line[y][x]=='.') ne=1;
	}
	wx=wo=0;
	chk(line[0][0],line[0][1],line[0][2],line[0][3]);
	chk(line[1][0],line[1][1],line[1][2],line[1][3]);
	chk(line[2][0],line[2][1],line[2][2],line[2][3]);
	chk(line[3][0],line[3][1],line[3][2],line[3][3]);
	chk(line[0][0],line[1][0],line[2][0],line[3][0]);
	chk(line[0][1],line[1][1],line[2][1],line[3][1]);
	chk(line[0][2],line[1][2],line[2][2],line[3][2]);
	chk(line[0][3],line[1][3],line[2][3],line[3][3]);
	chk(line[0][0],line[1][1],line[2][2],line[3][3]);
	chk(line[0][3],line[1][2],line[2][1],line[3][0]);
	
	if(wx) {
		_PE("Case #%d: X won\n",_loop);
	}
	else if(wo) {
		_PE("Case #%d: O won\n",_loop);
	}
	else {
		if(ne) {
			_PE("Case #%d: Game has not completed\n",_loop);
		}
		else {
			_PE("Case #%d: Draw\n",_loop);
		}
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



