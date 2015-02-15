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
int D[1001];
int last[1001],len[1001];
int Max;

void proc(int id) {
	int i,tested;
	int min=9999;
	
	if(id==N) {
		FOR(i,1000) {
			if(last[i]==0) break;
			if(min > len[i]) min=len[i];
		}
		if(min > Max && min<9999){
			Max = min;
		}
		return ;
	}
	
	tested = 0;
	//�����̂Ƃ���łȂ�����Ƃ��낪���邩�H
	for(i=0;i<1001;i++) {
		if(last[i]==0) {
			break;
		}
		
		if(last[i]==D[id]-1) {
			last[i]=D[id];
			len[i]++;
			proc(id+1);
			last[i]=D[id]-1;
			len[i]--;
			tested=1;
		}
	}
	
	if(tested==0) {
		last[i]=D[id];
		len[i]++;
		proc(id+1);
		last[i]=D[id]-1;
		len[i]--;
	}
}

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	double br,tb1,tb2,start,end;
	char list[1000],ts[2],ress[1000];
	int prep,maxv,st,ed,sv;;
	long long s,t,p;
	
	N=GETi();
	
	FOR(i,N) {
		D[i] = GETi();
	}
	
	FOR(i,N) {
		for(j=0;j<N-1;j++) {
			if(D[j] > D[j+1]) {
				k = D[j];
				D[j]=D[j+1];
				D[j+1] = k;
			}
		}
	}
	
	Max = 0;
	ZERO(last);
	ZERO(len);
	
	proc(0);

	
	_PE("Case #%d: %d\n",_loop, Max);
	
	
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



