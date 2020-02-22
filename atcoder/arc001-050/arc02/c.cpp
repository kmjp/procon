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
char line[3000];
int memo[3000];
int pmemo[3000];
int L,R;

int score_sub(int pos) {
	int t;
	if(pos>=N) return 0;
	if(memo[pos]==-1) {
		
		memo[pos] = score_sub(pos+1)+1;
		if(pos<N-1 && (line[pos]*4+line[pos+1]==L || line[pos]*4+line[pos+1]==R)) {
			t=score_sub(pos+2)+1;
			if(t<memo[pos]) memo[pos]=t;
		}
		else {
		}
		
	}
	return memo[pos];
}


int score() {
	int i,s;
	
	FOR(i,N) memo[i]=-1;
	
	return score_sub(0);
}

void solve() {
	int i,j;
	int res[4];
	char str[101];
	int min;
	int pair[16];
	
	ZERO(pair);
	N=GETi();
	GETs(line);
	FOR(i,N) {
		if(line[i]=='A') line[i]=0;
		if(line[i]=='B') line[i]=1;
		if(line[i]=='X') line[i]=2;
		if(line[i]=='Y') line[i]=3;
	}
	FOR(i,N-1) {
		pair[line[i]*4+line[i+1]]++;
	}
	
	min=N;
	FOR(L,16) {
		for(R=L+1;R<16;R++) {
			i=score();
			if(i<min){
				min=i;
			}
		}
	}
	FOR(i,N) {
		//_P("%d %d\n",i,pmemo[i]);
	}
	
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



