/* W・Hが4以下のみ */

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


int W,H;
char str[20][20];
deque<int> dfs;

int bitcount(int n) {
	int i=0;
	while(n>0) {i += n%2; n>>=1;}
	return i;
}

int valid(int mask) {
	int y,x;
	char m[20][20];
	
	
	memcpy(m,str,sizeof(m));
	
	//花を置けるか
	FOR(y,H) FOR(x,W) {
		if(mask & (1<<(x+y*W))) {
			if(m[y][x] != '.') return 0;
			m[y][x] = 'F';
		}
	}
	
	//家の入口は１か所か
	FOR(y,H) FOR(x,W) {
		if(m[y][x]!='H') continue;
		int r=0;
		
		int dx[4]={ 1,-1,0,0};
		int dy[4]={ 0,0,1,-1};
		int loop;
		FOR(loop,4) {
			int tx=x+dx[loop];
			int ty=y+dy[loop];
			if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
			if(m[ty][tx]=='.') r++;
		}
		if(r==0) return 0;
	}
	
	//すべての家は一つながりか？
	FOR(y,H) FOR(x,W) {
		if(m[y][x]=='.') {
			m[y][x]='-';
			dfs.clear();
			dfs.push_back(y*100+x);
			while(!dfs.empty()) {
				int key = dfs.front();
				dfs.pop_front();
				int kx=key%100;
				int ky=key/100;
				int dx[4]={ 1,-1,0,0};
				int dy[4]={ 0,0,1,-1};
				int loop;
				FOR(loop,4) {
					int tx=kx+dx[loop];
					int ty=ky+dy[loop];
					if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
					if(m[ty][tx]=='.') {
						m[ty][tx]='-';
						dfs.push_back(ty*100+tx);
					}
				}
			}
			
			goto ooend;
		}
	}
	ooend:
	//2つあったらアウト
	FOR(y,H) FOR(x,W) if(m[y][x]=='.') return 0;
	return 1;
	
}

void solve() {
	int d,i,j,no,h,m,s,t,k,ne,x,y,min=9999;
	int ns=0,c,p;
	
	H=GETi();
	W=GETi();
	FOR(y,H) GETs(str[y]);
	
	// small only
	if(H*W>16) return;
	
	int mmax=-1;
	FOR(i,1<<(H*W)) {
		if(bitcount(i)<=mmax) continue;
		if(valid(i)) mmax=bitcount(i);
		
	}
	_P("%d\n",mmax);
	
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



