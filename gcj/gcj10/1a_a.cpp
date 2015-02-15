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

int N,K;
int T,R,C,NB,NG;
int tx,ty,dx,dy;
int block[12][12];
int gx[5],gy[5];

int d[10];
char line[1000];
char data[101][101];
char data2[101][101];
int ls[101];
int step[12][12][4];
int bok,rok;

int res() {
	int i,j,k,res,ok;
	
	ok=res=0;
	FOR(i,N) {
		FOR(j,N) {
			if(data[i][j]==0 || data[i][j]=='.') continue;
			if(data[i][j]=='B' && bok) continue;
			if(data[i][j]=='R' && rok) continue;
			if(bok && rok) return 0;
			//‰¡
			if(j<=N-K) {
				ok = data[i][j];
				FOR(k,K) {
					if(data[i][j+k]!=ok){ ok=0; break;}
				}
				if(ok=='B') bok=1;
				if(ok=='R') rok=1;
			}
			if(i<=N-K) {
				ok = data[i][j];
				FOR(k,K) {
					if(data[i+k][j]!=ok){ ok=0; break;}
				}
				if(ok=='B') bok=1;
				if(ok=='R') rok=1;
			}
			if(j<=N-K && i<=N-K) {
				ok = data[i][j];
				FOR(k,K) {
					if(data[i+k][j+k]!=ok){ ok=0; break;}
				}
				if(ok=='B') bok=1;
				if(ok=='R') rok=1;
			}
			if(j>=K-1 && i<=N-K) {
				ok = data[i][j];
				FOR(k,K) {
					if(data[i+k][j-k]!=ok){ ok=0; break;}
				}
				if(ok=='B') bok=1;
				if(ok=='R') rok=1;
			}
			
		}
	}
	return ok;
}


void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up;
	double br,tb1,tb2,start,end;
	int r1,r2;
	
	GET2(&N,&K);
	ZERO(data);
	FOR(i,N) {
		GETs(data[i]);
		j = -1;
		FOR(k,N) {
			if(data[i][k]!='.') {
				j++;
				data[i][j]=data[i][k];
			}
			if(j<k) data[i][k]=0;
		}
		//_E("%s\n",data[i]);
	}
	rok=bok=0;
	//r1 = res();
	//‰E‚Â‚ß
	FOR(i,N) {
		j = strlen(data[i]);
		if(j!=N) {
			FOR(k,j) data[i][N-1-k] = data[i][j-1-k];
			FOR(k,N-j) data[i][k] = '.';
		}
		_E("%s\n",data[i]);
	}
	
	r2 = res();
	
	if(rok==0 && bok==0) { _PE("Case #%d: Neither\n",_loop);}
	else if(rok==0 && bok==1) { _PE("Case #%d: Blue\n",_loop);}
	else if(rok==1 && bok==0) { _PE("Case #%d: Red\n",_loop);}
	else if(rok==1 && bok==1) { _PE("Case #%d: Both\n",_loop);}
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



