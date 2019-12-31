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

char str[5000];
char str2[5000];
int ml[4];

int m1(char a) {
	if(a=='S') return 0;
	if(a=='H') return 1;
	if(a=='D') return 2;
	if(a=='C') return 3;
}

int m2(char a) {
	if(a=='A') return 0;
	if(a=='T') return 1;
	if(a=='J') return 2;
	if(a=='Q') return 3;
	if(a=='K') return 4;
	return -1;
}

void solve() {
	int f,t,g;
	int m,d,i,j;
	int sum,max;
	int vx,vy;
	char ll[30];
	
	GETs(str);
	ZERO(str2);
	//10->T•ÏŠ·
	j=0;
	FOR(i,strlen(str)) {
		if(str[i]=='1') {
			str2[j++]='T';
			i++;
		}
		else {
			str2[j++]=str[i];
		}
	}
	ZERO(ml);
	int c=0;
	j=0;
	for(i=0;i<strlen(str2);i+=2) {
		if(m2(str2[i+1])==-1) continue;
		ml[m1(str2[i])] |= 1<<m2(str2[i+1]);
		if(ml[m1(str2[i])]==31) {
			c = m1(str2[i]);
			break;
		}
	}
	
	if(i==8) {
		_P("0\n");
	}
	else {
		for(j=0;j<i;j+=2) {
			if(m2(str2[j+1])>=0 && m1(str2[j])==c) continue;
			if(str2[j+1]=='T') _P("%c10",str2[j]);
			else _P("%c%c",str2[j],str2[j+1]);
		}
		_P("\n");
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



