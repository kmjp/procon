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


int T,K;
int data[205][205];
int num[205];
int vert[300];
int hori[300];



void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	double br,tb1,tb2,start,end;
	
	GET1(&K);
	MINUS(data);
	ZERO(num);
	ZERO(vert);
	ZERO(hori);
	
	FOR(i,2*K-1) {
		if(i<K) {
			num[i]=i+1;
		}
		else {
			num[i]=2*K-i-1;
		}
		FOR(j,num[i]) {
			data[i][j*2+K-num[i]]=GETi();
		}
		FOR(j,2*K-1) {
			//_E("%d",data[i][j]);
		}
		//_E("\n",0);
	}
	
	FOR(i,2*K-1) {
		hori[i]=1;
		vert[i]=1;
		if(i<K) {
			//êÖïΩé≤
			FOR(y,i) {
				FOR(x,2*K-1) {
					if(data[y][x] != data[2*i-y][x] && data[y][x]>=0){
						//_E("host out %d %d %d\n",i,y,x);
						hori[i]=0;
						break;
					}
				}
				if(hori[i]==0) break;
			}
			//êÇíºé≤
			FOR(x,i) {
				FOR(y,2*K-1) {
					if(data[y][x] != data[y][2*i-x] && data[y][x]>=0){
						//_E("vert out %d %d %d\n",i,y,x);
						vert[i]=0;
						break;
					}
				}
				if(vert[i]==0) break;
			}
			
		}
		else {
			//êÖïΩé≤
			for(y=i+1;y<2*K-1;y++) {
				FOR(x,2*K-1) {
					if(data[y][x] != data[2*i-y][x]&& data[y][x]>=0){
						hori[i]=0;
						break;
					}
				}
				if(hori[i]==0) break;
			}
			//êÇíºé≤
			for(x=i+1;x<2*K-1;x++) {
				FOR(y,2*K-1) {
					if(data[y][x] != data[y][2*i-x] && data[y][x]>=0){
						//_E("vert out %d %d %d\n",i,y,x);
						vert[i]=0;
						break;
					}
				}
				if(vert[i]==0) break;
			}
		}
	}
	
	result=10000000;
	FOR(y,2*K-1) {
		FOR(x,2*K-1) {
			//_E("%d %d hori %d vert %d \n",y,x,hori[y],vert[x]);
			
			if(hori[y]==0 || vert[x]==0) continue;
			dist1=abs(x-0)+abs(y-(K-1));
			dist2=abs(x-(2*K-2))+abs(y-(K-1));
			if(dist1<dist2) dist1=dist2;
			dist2=abs(x-(K-1))+abs(y-0);
			if(dist1<dist2) dist1=dist2;
			dist2=abs(x-(K-1))+abs(y-(2*K-2));
			if(dist1<dist2) dist1=dist2;
			
			if((x+y)%2!=(K-1)%2) {
				res=2*((dist1+1)/2);
				res=res*res-K*K;
			}
			else {
				res=sqr(dist1+1)-K*K;
			}
			//_E("%d %d %d\n",y,x,res);
			if(result>res){
				result= res;
				//_E("%d %d %d\n",y,x,res);
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



