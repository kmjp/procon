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
char line[1000];

//-------------------------------------------------------

int M,N;
int data[513][513];
int cb[513][513];
int finr[513];
int results[513];

int makecb() {
	int i,j,k,l,result,dir,ok,state,fstate,up,y,x,ce,ng,maxc;
	
	maxc=0;
	ZERO(cb);
	ZERO(results);
	FOR(y,M) {
		FOR(x,N) {
			//_E("start %d %d\n",y,x);
			if(data[y][x]>1){
				cb[y][x]=0;
				continue;
			}
			ce = data[y][x];
			
			for(k=2;;k++) {
				if(y+k-1>=M || x+k-1>=N) break;
				ng=0;
				FOR(l,k) {
					if(data[y+k-1][x+l]>1 || data[y+l][x+k-1]>1){
						ng=1;
						break;
					}
					if(data[y+k-1][x+l] != ((k-1+l)&1) ^ ce) {
						ng=1;
						//_E("NG %d %d %d %d  %d %d\n",y,x,y+k-1,x+l, ce,data[y+k-1][x+l]);
						break;
					}
					if(data[y+l][x+k-1] != ((k-1+l)&1) ^ ce) {
						ng=1;
						//_E("NG %d %d %d %d  %d %d\n",y,x,y+k-1,x+l, ce,data[y+k-1][x+l]);
						break;
					}
				}
				if(ng) break;
			}
			k--;
			cb[y][x]=k;
			//_E("cb %d %d %d\n",y,x,k);
			results[k]++;
			if(k>maxc) maxc=k;
			
		}
	}
	return maxc;
}


void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,maxc;
	int x,y,tx,ty;
	double l,p;
	int r1,r2;
	char c;
	
	GET2(&M,&N);
	FOR(i,M) {
		GETs(line);
		FOR(j,N) {
			c = line[j/4];
			c = (c>='A' ? c-'A'+10 : c-'0');
			data[i][j] = (c>>(3-j%4))&1;
			//_E("%d",data[i][j]);
		}
		//_E("\n",0);
	}
	
	//ç≈ëÂílÇíTÇ∑
	ZERO(finr);
	while(1) {
		maxc = makecb();
		//_E("m=%d %d\n",maxc,results[maxc]);
		if(maxc==0) break;
		if(maxc==1) {
			finr[maxc]=results[maxc];
			break;
		}
		FOR(y,M) {
			FOR(x,N) {
				if(cb[y][x]==maxc) {
					//_E("%d %d %d\n",y,x,maxc);
					finr[maxc]++;
					for(ty=y;ty<y+maxc;ty++) {
						for(tx=x;tx<x+maxc;tx++) {
							data[ty][tx]=2;
							cb[ty][tx]=0;
						}
					}
					for(ty=y+1;ty<y+maxc;ty++) {
						for(tx=x-maxc+1;tx<x;tx++) {
							if(ty<M && tx>=0 && cb[ty][tx]==maxc) {
								cb[ty][tx]=0;
							}
						}
					}
				}
			}
		}
	}
	
	result=0;
	for(i=1;i<=512;i++) {
		if(finr[i]) result++;
	}
	
	_PE("Case #%d: %d\n",_loop,result);
	for(i=512;i>=1;i--) {
		if(finr[i]){ _PE("%d %d\n",i,finr[i]);}
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



