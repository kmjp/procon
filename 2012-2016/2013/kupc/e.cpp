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
#include <unistd.h>

typedef signed long long ll;
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

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int M;
int A[6];
int S,G;
int GT[301][6][2],N[301];
int dist[301][301];

void solve() {
	int f,r,i,j,k,l,x,y,tx,ty;
	
	M=GETi();
	FOR(i,6) A[i]=GETi();
	S=GETi()-1;
	G=GETi()-1;
	FOR(i,M) N[i]=GETi();
	
	FOR(y,M) FOR(x,M) dist[y][x]=301;
	
	FOR(x,M) {
		FOR(y,6) {
			GT[x][y][0]=GT[x][y][1]=-1;
			if(x+A[y]<M) {
				GT[x][y][0]=x+A[y]+N[x+A[y]];
				dist[x][x+A[y]+N[x+A[y]]]=1;
			}
			if(x-A[y]>=0) {
				GT[x][y][1]=x-A[y]+N[x-A[y]];
				dist[x][x-A[y]+N[x-A[y]]]=1;
			}
		}
	}
	dist[G][G]=0;
	
	FOR(i,M) FOR(j,M) FOR(k,M) dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
	
	for(i=0;i<3000 && S!=G;i++) {
		scanf("%d", &j);
		j--;
		k=S;l=0;
		if(GT[S][j][0]!=-1 && dist[GT[S][j][0]][G]<dist[k][G]) k=GT[S][j][0],l=1;
		if(GT[S][j][1]!=-1 && dist[GT[S][j][1]][G]<dist[k][G]) k=GT[S][j][1],l=-1;
		printf("%d\n",l);
		fflush(stdout);
		S=k;
	}
	return;
	
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
