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
template <class T> T smin(T &l,T r){ if(l>r) l=r;}
template <class T> T smax(T &l,T r){ if(l<r) l=r;}

//-------------------------------------------------------


int D,I,M,N;
char line[1000];
char data[41][41];
int step[101][256];
int array[101];

void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,w,d,d2;
	double br,tb1,tb2,start,end;
	
	GET2(&D,&I);
	GET2(&M,&N);
	ZERO(array);
	FOR(i,N) {
		GET1(&array[i]);
	}
	ZERO(step);
	FOR(i,256){
		step[0][i]=min(abs(i-array[0]),D);
	}
	
	for(i=1;i<N;i++) {
		FOR(j,256) {
			step[i][j]=step[i-1][j]+D;
			smin(step[i][j],step[i-1][j]+abs(j-array[i]));
			FOR(k,256) {
				d = abs(j-k);
				d2 = abs(j-array[i]);
				if(M>0 && d>0) {
					smin(step[i][j], step[i-1][k] + ((d-1)/M)*I + d2);
				}
			}
		}
	}
	
	
	result=999999;
	FOR(i,256) smin(result,step[N-1][i]);
	
	
end1:
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



