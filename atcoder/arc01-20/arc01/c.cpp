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
 
int qx[10],qy[10];
int nq;
 
int check() {
	int i,j;
	
	for(i=0;i<nq;i++) {
		for(j=i+1;j<nq;j++) {
			if(qx[i]==qx[j] || qy[i]==qy[j]) return 1;
			if(qx[i]+qy[i] == qx[j]+qy[j]) return 1;
			if(qx[i]-qy[i] == qx[j]-qy[j]) return 1;
		}
	}
	return 0;
}
 
int test() {
	int i,j,numq,y,x;
	char line[10];
	if(check()==1) return 1;
	if(nq==8) {
		line[8]=0;
		FOR(y,8) {
			FOR(x,8) {
				line[x]='.';
				FOR(i,8) {
					if(qx[i]==x && qy[i]==y){ line[x]='Q';}
				}
			}
			_P("%s\n",line);
		}
		return 0;
	}
	
	FOR(y,8) {
		FOR(x,8) {
			qx[nq]=x;
			qy[nq]=y;
			nq++;
			i = test();
			if(i==0) return 0;
			nq--;
		}
	}
	return 1;
	
	
	
}
 
 
void solve() {
	int i,j,k,m,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei,n;
	double br,tb1,tb2,start,end;
	int St,Sf,Pt,Pf,dig,mask;
	char maps[10];
	
	nq=0;
	
	FOR(i,8) {
		GETs(maps);
		FOR(j,8) {
			if(maps[j]=='Q') {
				qx[nq]=j;
				qy[nq]=i;
				nq++;
			}
		}
	}
	
	if(test()==1) {
		_P("No Answer\n");
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