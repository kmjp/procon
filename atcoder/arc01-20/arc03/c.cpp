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
char m[505][505];
int im[505][505];
int sx,sy;
int gx,gy;

int mins[505][505];
int up[505][505];
struct xy {
	int x,y;
};
deque<xy> uplist;
long double pw[10][80001];

int check(long double p){
	int x,y,sec,i,lll,ok,tok;
	int dy,dx,s;
	long double ba,ta,res=0,pl;

	FOR(s,2) {
		uplist.clear();
		
		struct xy up1;
		up1.x=sx;
		up1.y=sy;
		uplist.push_back(up1);
		ZERO(up);
		
		
		up[sy][sx]=1;
		ok=0;
		FOR(y,N) {
			FOR(x,M) {
				mins[y][x]=10000000;
			}
		}
		mins[sy][sx]=s;
		
		while(!uplist.empty()) {
			struct xy txy = uplist.front();
			struct xy txy2;
			uplist.pop_front();
			up[txy.y][txy.x]=0;
			
			x=txy.x;
			y=txy.y;
			int dx,dy;
			//_P("%d %d %d\n",x,y,mins[y][x]);
			
			sec = mins[y][x]+1;
			for(i=0;i<4;i++) {
				if(i==0) { dy=y-1;dx=x;}
				if(i==1) { dy=y+1;dx=x;}
				if(i==2) { dy=y;dx=x-1;}
				if(i==3) { dy=y;dx=x+1;}
				
				if(dy==gy&&dx==gx) return 1;
				if(dy>=0&&dy<N&&dx>=0&&dx<M&&im[dy][dx]!=-1) {
					if(mins[dy][dx]>sec) {
						//ta=im[dy][dx]*powl(0.99, sec);
						if(sec>=80000) ta=0;
						else ta=pw[im[dy][dx]][sec];
						if(ta>=p){
							if(up[dy][dx]==0) {
								txy2.x=dx;
								txy2.y=dy;
								uplist.push_back(txy2);
							}
							up[dy][dx]=1;
							mins[dy][dx]=sec;
						}
					}
				}
				
			}
		}
	}
	return 0;
}

void solve() {
	int x,y,sec,i,lll,ok,tok;
	long double lb,ub,p;

	GET2(&N,&M);
	
	tok=0;
	FOR(x,10) {
		pw[x][0]=x;
		FOR(i,80000) {
			pw[x][i+1]=pw[x][i]*0.99;
		}
	}
	FOR(y,N) {
		GETs(m[y]);
		FOR(x,M) {
			if(m[y][x]=='s') {
				sx=x;sy=y;im[y][x]=-1;
			}
			else if(m[y][x]=='g') {
				gx=x;gy=y;im[y][x]=99999999;
			}
			else if(m[y][x]>='1' && m[y][x]<='9') {
				im[y][x]=m[y][x]-'0';
			}
			else {
				im[y][x]=-1;
			}
		}
	}
	
	//check
	if(check(-1)==0){
		_P("-1\n");
		return;
	}
	
	lb=-10;
	ub=10;
	FOR(lll,50) {
		p=(lb+ub)/2;
		
		ok=check(p);
		if(ok) {
			lb=p;
		}
		else {
			ub=p;
		}
	}
	
	_P("%.13f\n",(double)p);
	
	
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



