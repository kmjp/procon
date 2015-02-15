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

char ts[26][500];
int N;
int m[50][50];
int nc;
char cities[50][30];
int ttim[50];

int up[50];
deque<int> uplist;

int addcity(char* c){
	int i;
	FOR(i,nc) {
		if(strcmp(cities[i],c)==0) return i;
	}
	strcpy(cities[nc],c);
	nc++;
	return nc-1;
}
int tim(char* c){
	int h,m;
	
	h=(c[0]-'0')*10+(c[1]-'0');
	m=(c[3]-'0')*10+(c[4]-'0');
	return h*60+m;
}

void solve() {
	int i,j;
	int x,y,t1,t2;
	char cs[256];
	
	FOR(i,50) {
		FOR(j,50) {
			m[i][j]=-99999;
		}
	}
	
	nc=0;
	GETs(cs);
	x=addcity(cs);
	
	FOR(i,24) GETs(ts[i]);
	N=GETi();
	
	FOR(i,N) {
		GETs(cs);
		x = addcity(cs);
		GETs(cs);
		t1 = tim(cs);
		GETs(cs);
		y = addcity(cs);
		GETs(cs);
		t2 = tim(cs);
		m[x][y]=t2-t1;
		m[y][x]=t1-t2;
	}
	
	int tar;
	GETs(cs);
	tar=addcity(cs);
	FOR(i,50){
		ttim[i]=-99999999;
	}
	

	GETs(cs);
	ttim[tar]=tim(cs);
	ZERO(up);
	uplist.clear();
	up[tar]=1;
	uplist.push_back(tar);
	while(!uplist.empty()) {
		int tar = uplist.front();
		uplist.pop_front();
		up[tar]=0;
		
		FOR(i,nc) {
			if(ttim[i]==-99999999 && m[tar][i]!=-99999) {
				ttim[i]=ttim[tar]+m[tar][i];
				if(up[i]==0) {
					uplist.push_back(i);
					up[i]=1;
				}
			}
		}
	}
	FOR(i,nc) {
		j = ttim[i];
		j = ((j % (24*60))+(24*60))%(24*60);
	}
	
	i = ttim[0];
	i = ((i % (24*60))+(24*60))%(24*60);
	i/=60;
	
	_P("%s\n",ts[i]);
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



