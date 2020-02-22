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
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) { printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__); }
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
ll GETi() { ll i;scanf("%lld",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int A,T,K,M,TTC;
int N[100];
int C[100][10];
int MC[100];
int R[600][600];
int cost[100][500];
ll CO[40000];

int bitcount(int n) {
	int i=0;
	while(n>0) {i += n%2; n>>=1;}
	return i;
}

//ëSàÊñÿÇãÅÇﬂÇÈ
void enumcost(int city) {
	int NE,NC,i,rc,x,y,mask;
	int tx[7],ty[7],tn,tt;
	
	NC=N[city];
	MC[city]=0;
	
	FOR(x,NC) for(y=x+1;y<NC;y++) TTC += R[C[city][x]][C[city][y]];
	tt=0;
	NE=NC*(NC-1)/2;
	for(mask=1;mask<1<<NE;mask++) {
		int bc=bitcount(mask);
		int ng=0;
		if(bc!=NC-1) continue;
		tn=rc=0;
		x=0;y=0;
		int id;
		FOR(id,NE) {
			y++;
			if(y>=NC) {
				x++;
				y=x+1;
			}
			if(!(mask & (1<<id))) continue;
			tx[tn]=x;
			ty[tn]=y;
			tn++;
			rc += R[C[city][x]][C[city][y]];
			if(R[C[city][x]][C[city][y]]==0) ng++;
		}
		if(ng) continue;
		int ma=1;
		FOR(i,7) {
			FOR(id,tn) if(ma & ((1<<tx[id])|(1<<ty[id])))   ma |= (1<<tx[id]) | (1<<ty[id]);
		}
		if(ma==(1<<NC)-1){
			cost[city][rc]++;
			MC[city] = max(MC[city], rc);
			tt++;
		}
	}
}

void solve() {
	int x,y,i,j,rr,TM;
	ll p;
	
	GET3(&A,&T,&K);
	TTC=0;
	ZERO(N);
	ZERO(C);
	ZERO(cost);
	ZERO(R);
	
	FOR(i,A) {
		N[i]=GETi();
		FOR(j,N[i]) C[i][j]=GETi()-1;
	}
	
	M=GETi();
	FOR(i,M) {
		x=GETi()-1;
		y=GETi()-1;
		R[x][y]=R[y][x]=GETi();
	}
	
	FOR(i,A) enumcost(i);
	
	ZERO(CO);
	CO[0]=1;
	FOR(i,A) {
		for(j=77*77*6;j>=0;j--) {
			if(CO[j]==0) continue;
			FOR(x,MC[i]+1) if(cost[i][x]){
				CO[j+x] += CO[j]*cost[i][x];
				if(CO[j+x]>7777777) CO[j+x]=7777778;
			}
			CO[j]=0;
		}
	}
	
	for(j=77*77*6;j>=0;j--){
		if(CO[j]==0) continue;
		if(K<=CO[j]) {
			_P("%d\n",TTC-j);
			return;
		}
		K-=CO[j];
	}
	_P("%d\n",-1);
	return;
}

int main(int argc,char** argv){
	long long span;
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&start,NULL);
	solve();
	gettimeofday(&end,NULL);
	
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}


