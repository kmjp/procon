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
#include <assert.h>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

typedef signed long long s64;
typedef unsigned long long u64;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
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
#define SIGN(n) (n==0?0:(n>0 ? 1 : -1))
#define ABS(n) ((n)<0?(-(n)):(n))

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int T;
u64 S[600];
int SN[100000];
u64 SM[200][100000];
u64 ST[200][100000];


void out(u64 t1) {
	int i;
	int f=0;
	u64 total=0;
	
	FOR(i,64) {
		if(t1&(1ULL<<i)){
			total+=S[i];
			if(f!=0){
				_P(" ");
			}
			f=1;
			_P("%llu",S[i]);
		}
	}
	_P("\n",total);
}


void solve(int _loop) {
	int i,j,ind,result,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,step;
	u64 wid,hei,total;
	int dx,dy,star;
	u64 mask;
	u64 k;
	
	T=GETi();
	FOR(i,T) {
		scanf("%llu",&S[i]);
	}
	//sort
	FOR(i,T) {
		for(j=i+1;j<T;j++) {
			if(S[i]<S[j]) {
				k=S[i];
				S[i]=S[j];
				S[j]=k;
			}
		}
	}
	
	_PE("Case #%d:\n",_loop);
	ZERO(SM);
	ZERO(SN);
	ZERO(ST);
	srand(result+time(NULL));
	j=0;
	while(1) {
		j++;
		mask = ((((u64)rand())<<31) | (u64)rand());
		if(T<64) mask &= ((1ULL<<T)-1);
		
		if(mask==0) continue;
		total=0;
		FOR(i,64) {
			if(mask&(1ULL<<i)){
				total+=S[i];
			}
		}
		ind=total%100000;
		if(SN[ind]>=200) {
			break;
		}
		FOR(i,SN[ind]) {
			if(ST[i][ind]==total && SM[i][ind]!=mask) {
				out(mask);
				out(SM[i][ind]);
				return;
			}
		}
		SM[SN[ind]][ind]=mask;
		ST[SN[ind]][ind]=total;
		SN[ind]++;
	}
	_PE("Impossible\n",_loop);
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
	
	if(loops>1000) {
		_E("loops is over 1000\n");
		return 0;
	}
	
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



