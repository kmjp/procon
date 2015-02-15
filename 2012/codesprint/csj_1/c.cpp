/* 部分点のみ */

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

int N,M;
int A[102],B[102],C[102],TC[102];
int SR[102],SU[102];


int getl(int okok) {
	int i,j,k;
	
	FOR(i,M){ TC[i]=C[i];}
	ZERO(SR);
	FOR(i,M) {
		if(TC[i]>0) {
			for(j=A[i];j<=B[i];j++) {
				SR[j]++;
			}
		}
	}
	
	ZERO(SU);
	
	while(1) {
		int maxsr=0,maxid;
		FOR(i,N){
			if(SR[i]>maxsr && SU[i]==0) {
				maxsr=SR[i];
				maxid=i;
			}
		}
		
		if(maxsr==0) break;
		
		int ok;
		//とらずに済むか？
		if(okok) {
			// minを求めるなら必ず取る
			ok=0;
		}
		else {
			// maxを求めるなら、できるだけとらない
			ok=1;
			FOR(i,M){
				if(A[i]<=maxid && B[i]>=maxid && TC[i]>0) {
					int j,sp=0,n=0;
					for(j=A[i];j<=B[i];j++) {
						if(SU[j]==2) sp++;
						if(SU[j]==1) n++;
					}
					if(B[i]+1-A[i] - sp - n <= C[i]-n) {
						ok=0;
						break;
					}
				}
			}
		}
		
		if(ok) {
			SU[maxid]=2;
			
		}
		else {
			SU[maxid]=1;
			FOR(i,M){
				if(A[i]<=maxid && B[i]>=maxid && TC[i]>0) {
					TC[i]--;
					if(TC[i]==0){
						for(j=A[i];j<=B[i];j++) {
							SR[j]--;
						}
					}
					
				}
			}
		}
		
		
	}
	j=0;
	FOR(i,N) {if(SU[i]==1) j++;}
	return j;
}

void solve(int _loop) {
	s64 na,nb,r;
	int i,j;
	
	GET2(&N,&M);
	FOR(i,M) {
		A[i]=GETi()-1;
		B[i]=GETi()-1;
		C[i]=GETi();
	}
	
	_P("%d %d\n",getl(1),getl(0));
	
	
	
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
	
	
	solve(loop);
	
	
	return 0;
	
}



