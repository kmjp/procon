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



int ymday(int y,int m) {
	int dd[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(y%400==0) dd[2]++;
	else if(y%100!=0 && y%4==0) dd[2]++;
	
	return dd[m];
}

void solve() {
	int N,K;
	int ok=0;
	int x[101];
	int i,j,k,l,t;
	int y,m,d,h,mm,s,add;
	char str[100];
	time_t tim;
	struct tm tm;
	
	while(1){
		i=scanf("%d/%d/%d %d:%d:%d",&y,&m,&d,&h,&mm,&s);
		if(i<2) return;
		GETs(str);
		add = (1<<(strlen(str)))-1;
		
		s += add%60;
		add = add/60;
		if(s>=60){ add++; s-=60;}
		mm += add%60;
		add = add/60;
		if(mm>=60){ add++; mm-=60;}
		h += add%24;
		add = add/24;
		if(h>=24){ add++; h-=24;}
		
		while(add--) {
			d++;
			if(d>ymday(y,m)) {
				d=1;
				m++;
				if(m>12) {
					y++;
					m=1;
				}
			}
		}
		
		_P("%04d/%02d/%02d %02d:%02d:%02d\n",y,m,d,h,mm,s);
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
	
	init();
	solve();
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



