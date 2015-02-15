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

int R,C;
char str[700][700];
int mo=1000000007;
s64 dp[2][400][400];

void solve() {
	int x,y,i,j,dist,t1,t2,tx,ty,dx,dy,m;
	s64 res=4;
	
	GET2(&R,&C);
	ZERO(str);
	FOR(y,R) GETs(str[y]);
	
	ZERO(dp);
	dp[0][0][0]=4;
	
	for(dist=1;dist<=R+C-1;dist++) {
		t1 = dist%2;
		t2 = 1-t1;
		
		FOR(tx,dist+1) {
			if(tx>=C) continue;
			ty = dist-tx;
			if(ty<0 || ty>=R) continue;
			
			FOR(dx,dist+1) {
				if(dx>=C) continue;
				dy = dist-dx;
				if(dy<0 || dy>=R) continue;
				
				dp[t1][tx][dx]=0;
				//_P("%d %d,%d %d,%d %d\n",dist,tx,ty,dx,dy,dp[t1][tx][dx]);
				
				if(str[ty][tx]!=str[dy][dx]) continue;
				//T‚Éã‚©‚ç“ü‚é
				if(ty>0) {
					m=(tx==C-1)?2:1;
					//D‚Éã‚©‚ç“ü‚é
					if(dy>0) dp[t1][tx][dx] += m*dp[t2][tx][dx];
					//D‚É¶‚©‚ç“ü‚é
					if(dx>0) dp[t1][tx][dx] += m*dp[t2][tx][dx-1];
				}
				//T‚É¶‚©‚ç“ü‚é
				if(tx>0) {
					m=(ty==R-1)?2:1;
					if(dy>0) dp[t1][tx][dx] += m*dp[t2][tx-1][dx];
					//D‚É¶‚©‚ç“ü‚é
					if(dx>0) dp[t1][tx][dx] += m*dp[t2][tx-1][dx-1];
				}
				dp[t1][tx][dx] %= mo;
				res =dp[t1][tx][dx];
				//_P("%d %d %d %d\n",dist,tx,dx,dp[t1][tx][dx]);
			}
			
		}
	}
	
	_P("%lld\n",res);
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



