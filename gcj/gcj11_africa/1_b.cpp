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

#define GETai(n,x) {int _i; for(i=0;i<n;i++) scanf("%d",&x[i]); }
#define GETas(n,x) {int _i; for(i=0;i<n;i++) scanf("%s",&x[i]); }

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


int N,R;
int mat[1001][1001];
int edge[1001];

int ngr;
int caedge;
int aedge[1001];
int visited[1001];

void DFS(int i) {
	int j;
	if(edge[i]%2==1) caedge++;
	visited[i]=1;
	FOR(j,N) {
		if(mat[i][j] && visited[j]==0) {
			DFS(j);
		}
	}
	
}


void split() {
	int i;
	ZERO(visited);
	FOR(i,N) {
		
		caedge=0;
		if(edge[i]>0 && visited[i]==0){
			DFS(i);
			aedge[ngr++] = caedge;
		}
	}
	/*
	FOR(i,ngr) {
		_E("%d ",aedge[i]);
	}
	_E("\n");
	*/
}

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,isb,left,rep;
	double br,tb1,tb2,start,end;
	
	char tmp[1000];
	
	ZERO(mat);
	ZERO(edge);
	ngr = 0;
	ZERO(aedge);
	
	N = GETi();
	R = GETi();
	
	FOR(i,R) {
		j=GETi();
		k=GETi();
		
		mat[j][k]++;
		mat[k][j]++;
		edge[j]++;
		edge[k]++;
		
	}
	
	split();
	
	if(ngr==1) result = aedge[0]/2;
	else {
		result = ngr;
		res=0;
		FOR(i,ngr) {
			if(aedge[i]>=2) {
				aedge[i] -= 2;
			}
			if(aedge[i]>0) res++;
		}
		
		while(res>0) {
			if(res==1) {
				FOR(i,ngr) {
					if(aedge[i]>=2) {
						result+=aedge[i]/2;
						res=0;
						break;
					}
				}
			}
			else {
				result += res;
				res=0;
				FOR(i,ngr) {
					if(aedge[i]>=2) {
						aedge[i] -= 2;
					}
					if(aedge[i]>0) res++;
				}
			}
		}
		
	}
	
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



