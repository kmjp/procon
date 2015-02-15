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


int P;
int data[11][2000];

int calc(int step,int match) {
	int start,num;
	int nmiss,nmust,i;
	int rest,resnt;
	
	if(P<=step) return 0;
	
	num=1<<(P-step);
	start=num*match;
	//‘S•”miss‚µ‚Ä‚æ‚¢
	nmiss=nmust=0;
	for(i=start;i<start+num;i++) {
		if(data[0][i]==0) nmust++;
		if(data[0][i]==P-step) nmiss++;
	}
	if(nmiss==num) return 0;
	if(nmust) {
		rest=data[P-step][match] + calc(step+1,match*2) + calc(step+1,match*2+1);
		//_E("%d %d %d %d   %d %d\n",step,match,start,num,rest,0);
		return rest;
	}
	else {
		//‚Æ‚éê‡
		rest=data[P-step][match] + calc(step+1,match*2) + calc(step+1,match*2+1);
		//_E("%d %d %d %d   %d %d\n",step,match,start,num,rest,1);
		
		//‚Æ‚ç‚È‚¢ê‡
		for(i=start;i<start+num;i++) data[0][i]--;
		resnt = calc(step+1,match*2) + calc(step+1,match*2+1);
		//_E("%d %d %d %d   %d %d\n",step,match,start,num,resnt,2);
		for(i=start;i<start+num;i++) data[0][i]++;
		if(resnt<rest) rest=resnt;
		//_E("%d %d %d %d   %d %d\n",step,match,start,num,rest,1);
		return rest;
	}
	
}

void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up;
	double br,tb1,tb2,start,end;
	
	GET1(&P);
	FOR(i,P+1){
		FOR(j,1<<(P-i)){
			GET1(&data[i][j]);
		}
	}
	
	result=calc(0,0);
	
	_PE("Case #%d: %d\n",_loop,result);
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



