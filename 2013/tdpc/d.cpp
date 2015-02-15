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

ll N,D;
int num[6];

double dpdp[2][70][70][70];

void solve() {
	int f,r,i,j,k,l, x,y,z;
	
	cin>>N>>D;
	while(D%2==0) num[2]++,D/=2;
	while(D%3==0) num[3]++,D/=3;
	while(D%5==0) num[5]++,D/=5;
	if(D>1) return _P("%lf\n",0.0);
	
	dpdp[0][0][0][0]=1.0f;
	FOR(i,N) {
		int cur=i%2;
		int tar=1^cur;
		ZERO(dpdp[tar]);
		
		FOR(x,70) FOR(y,50) FOR(z,40) {
			if(dpdp[cur][x][y][z]==0) continue;
			dpdp[tar][x][y][z]                     += dpdp[cur][x][y][z]/6.0; //1
			dpdp[tar][min(69,x+1)][y][z]           += dpdp[cur][x][y][z]/6.0; //2
			dpdp[tar][x][min(49,y+1)][z]           += dpdp[cur][x][y][z]/6.0; //3
			dpdp[tar][min(69,x+2)][y][z]           += dpdp[cur][x][y][z]/6.0; //4
			dpdp[tar][x][y][min(39,z+1)]           += dpdp[cur][x][y][z]/6.0; //5
			dpdp[tar][min(69,x+1)][min(49,y+1)][z] += dpdp[cur][x][y][z]/6.0; //6
		}
	}
	
	double ret=0;
	for(x=num[2];x<70;x++) for(y=num[3];y<50;y++) for(z=num[5];z<40;z++) ret += dpdp[N%2][x][y][z];
	_P("%.12lf\n",ret);
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


