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


int A1,A2,B1,B2;
int tx,ty,dx,dy;
int block[12][12];
int gx[5],gy[5];

int d[10];
char line[1000];
char data[41][41];
int step[12][12][4];
int memo[1000][1000];
double phi;

int check(int l,int s,int t) {
	int i,r,ok,v1,v2;
	if(l%s==0) return 1;
	if(l<1000&&s<1000&&memo[l][s]>=0) return memo[l][s];
	
	if(l>2*s) {
		ok = 1-check(s,l-s,1-t);
		if(l<1000) memo[l][s]=ok;
		return ok;
	}
	
	for(i=1;i<=l/s;i++) {
		if(l-i*s>s) { v1=l-i*s; v2=s;}
		else { v1=s; v2=l-i*s; }
		
		ok = check(v1,v2,1-t);
		if(ok==0) {
			if(l<1000 && s<1000) memo[l][s]=1;
			//_E("%d %d %d (%d)\n",l,s,1,t);
			return 1;
		}
	}
	
	if(l<1000 && s<1000) memo[l][s]=0;
	//_E("%d %d %d (%d)\n",l,s,0,t);
	return 0;
	
}



void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,v1,v2,l,h;
	long long res;
	double br,tb1,tb2,start,end;
	
	GET2(&A1,&A2);
	GET2(&B1,&B2);
	
	res=0;
	for(i=A1;i<=A2;i++) {
		l=1+(int)(i/phi);
		h=(int)(i*phi);
		
		if(h<B1 || l>B2) { res+=(B2-B1+1); continue;}
		if(h>B2) h=B2;
		if(l<B1) l=B1;
		res += (B2-B1+1) - (h-l+1);
	}
	
	
	_PE("Case #%d: %lld\n",_loop,res);
}

void init() {
	phi = (1+sqrt(5))/2;
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



