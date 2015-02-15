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

int N;
char mat[101][101];
int win[101];
int lose[101];
int match[101];
double WP[101],OWP[101],OOWP[101];

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,isb;
	double br,tb1,tb2,start,end;
	int Bpos,Opos,Btim,Otim,walk,tim;
	
	N=GETi();
	ZERO(mat);
	ZERO(win);
	ZERO(lose);
	ZERO(WP);
	ZERO(OWP);
	ZERO(OOWP);
	
	FOR(i,N){
		GETs(mat[i]);
		
		FOR(j,N) {
			if(mat[i][j]=='1') win[i]++;
			if(mat[i][j]=='0') lose[i]++;
		}
		match[i] = win[i]+lose[i];
	}
	
	FOR(i,N){
		WP[i] = win[i]/(double)match[i];
	}
	
	FOR(i,N){
		k=0;
		// jがiを除くときの勝率をカウント
		FOR(j,N){
			if(mat[i][j]=='1'){
				k++;
				OWP[i] += (win[j])/(double)(match[j]-1);
			}
			else if(mat[i][j]=='0'){
				k++;
				OWP[i] += (win[j]-1)/(double)(match[j]-1);
			}
		}
		OWP[i] /= (double)k;
	}
	
	
	FOR(i,N){
		k=0;
		// jがiを除くときの勝率をカウント
		FOR(j,N){
			if(mat[i][j]!='.'){
				OOWP[i] += OWP[j];
				k++;
			}
		}
		OOWP[i] /= (double)k;
	}
	
	
	_PE("Case #%d:\n",_loop);
	FOR(i,N){
		br = 0.25*WP[i] + 0.5*OWP[i] + 0.25*OOWP[i];
		_PE("%.10lf\n",br);
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



