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

int S,X,R,t,N;
int Len[1001],Sp[1001];

void solve(int _loop) {
	int i,j,k,l,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,isb;
	double br,tb1,tb2,start,end;
	int Bpos,Opos,Btim,Otim,walk;
	double tim,leftt;;
	
	X=GETi();
	S=GETi();
	R=GETi();
	t=GETi();
	N=GETi();
	
	ZERO(Len);
	Len[0] = X;
	Sp[0] = S;
	
	
	FOR(i,N){
		j = GETi();
		k = GETi();
		l = GETi();
		Len[i+1] = k-j;
		Len[0] -= k-j;
		Sp[i+1] = S+l;
	}
	
	//sort
	N++;
	FOR(i,N){
		for(j=i+1;j<N;j++) {
			if(Sp[j]<Sp[i]) {
				k=Sp[j];
				Sp[j]=Sp[i];
				Sp[i]=k;
				k=Len[j];
				Len[j]=Len[i];
				Len[i]=k;
			}
		}
	}
	FOR(i,N){
		//_P("%d %d\n",Len[i],Sp[i]);
	}
	
	tim=0;
	leftt = t;
	FOR(i,N) {
		if(Len[i]<=0) {
			continue;
		}
		if(leftt<=0) {
			tim += Len[i]/(double)Sp[i];
		}
		else if(Len[i] > (Sp[i]+R-S)*leftt) {
			tim += leftt + (Len[i]-(Sp[i]+R-S)*leftt)/(double)Sp[i];
			leftt = 0;
		}
		else {
			tim += Len[i]/(double)(Sp[i]+R-S);
			leftt -= Len[i] / (double)(Sp[i]+R-S);
		}
	}
	
	
	_PE("Case #%d: %.7lf\n",_loop,tim);
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



