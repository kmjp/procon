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

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N,M;
int m[1001][1001];
int s[1001][28];
int up[1001][28];
struct xy {
	int x,y;
};
deque<xy> uplist;


void solve() {
	int i,j,k,l,mi,x,y;
	GET2(&N,&M);
	MINUS(m);
	
	FOR(i,N) {
		FOR(j,28) {
			s[i][j]=-1;
			up[i][j]=0;
		}
	}
	
	FOR(i,M) {
		GET3(&j,&k,&l);
		m[j][k]=m[k][j]=l;
	}
	
	s[0][0]=0;
	up[0][0]=1;
	uplist.clear();
	struct xy txy;
	txy.x=0; txy.y=0;
	uplist.push_back(txy);
	
	int cs,ts;
	while(!uplist.empty()) {
		txy = uplist.front();
		uplist.pop_front();
		x=txy.x; y=txy.y;
		up[x][y]=0;
		cs=s[x][y];
		
		FOR(i,N) {
			if(m[x][i]==-1) continue;
			ts=cs+m[x][i];
			
			if(s[i][ts%28]==-1 || ts < s[i][ts%28]) {
				s[i][ts%28]=ts;
				if(up[i][ts%28]==0 && i!= N-1) {
					txy.x=i;
					txy.y=ts%28;
					uplist.push_back(txy);
					up[i][ts%28]=1;
				}
			}
		}
	}
	
	
	mi=-1;
	FOR(i,28){
		if((i%4==0 || i%7==0) && s[N-1][i]>=0 && (mi<0 || s[N-1][i]<mi)) mi=s[N-1][i];
	}
	
	_P("%d\n",mi);
	
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
	solve();
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



