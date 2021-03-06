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

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
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

int K,N;
int R[2000];
double rate[2000][2000];
double RR[11][2000];

void solve() {
	int f,r,i,j,k,l, x,y;
	
	cin>>K;
	N=1<<K;
	FOR(i,N) R[i]=GETi();
	
	FOR(x,N) FOR(y,N) rate[x][y]=1.0/(1.0+pow(10,(R[y]-R[x])/400.0));

	FOR(i,N) RR[0][i]=1;
	FOR(i,K) {
		x = 1<<i;
		FOR(j,N) {
			FOR(y,x) {
				int tar = (j/(2*x))*(2*x);
				if(j%(2*x)<x) tar += x;
				tar += y;
				
				RR[i+1][j] += RR[i][tar]*rate[j][tar];
			}
			RR[i+1][j] *= RR[i][j];
		}
	}
	
	FOR(i,N) _P("%.12lf\n",RR[K][i]);
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


