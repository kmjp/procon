// small‚Ì‚Ý

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


int N,M;
double px[5000],py[5000];
double qx[5000],qy[5000];
double len[5000];


double calc(double a,double r,double b) {
	double co,ta,si,th,s,s2,s3;
	
	co = (a*a+r*r-b*b)/(2*a*r);
	ta = sqrt(1/(co*co)-1);
	si = sqrt(1-co*co);
	th=acos(co);
	
	s2= a*a*th;
	s3= a*co*a*sin(th);
	s = s2-s3;
	
	//_E("++%f %f %f %f %f %f %f  **%f %f %f\n",a,r,b,co,ta,si,th,  s2,s3,s);
	return s;
}

void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,lp,x,y;
	double tl,res,r;
	
	GET2(&N,&M);
	FOR(i,N){
		GET2(&x,&y);
		px[i]=x;
		py[i]=y;
	}
	FOR(i,M){
		GET2(&x,&y);
		qx[i]=x;
		qy[i]=y;
	}
	_PE("Case #%d:",_loop);
	
	FOR(lp,M) {
		FOR(i,N){
			len[i]=sqrt(sqr(px[i]-qx[lp])+sqr(py[i]-qy[lp]));
		}
		tl=sqrt(sqr(px[0]-px[1])+sqr(py[0]-py[1]));
		
		res=calc(len[0],tl,len[1]) + calc(len[1],tl,len[0]);
		
		_PE(" %.8f",res);
	}
	_PE("\n",0);
	
	
	
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



