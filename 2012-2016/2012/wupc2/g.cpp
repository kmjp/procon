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

ll N,M,H;
ll hei[2001],th;
vector<int> blocks[2002];


void solve() {
	int x,y,i,j,rr,TM,nc;
	int tx,ty;
	char cmd[100];
	ll p,cch;
	
	N=GETi();
	M=GETi();
	H=GETi();
	ZERO(hei);
	th=0;
	FOR(i,N){
		p=GETi();
		blocks[i/1000].push_back(p);
		hei[i/1000]+=p;
		th+=p;
	}
	
	FOR(rr,M) {
		GETs(cmd);
		p=GETi();
		if(strcmp(cmd,"add")==0){
			N++;
			blocks[N/1000].push_back(p);
			hei[N/1000]+=p;
			th+=p;
		}
		else {
			cch=th;
			p-=H;
			FOR(i,2001) {
				if(p>=hei[i]) {
					p-=hei[i];
					cch-=hei[i];
				}
				else {
					ll ch=0;
					FOR(j,blocks[i].size()) {
						if(p<ch+blocks[i][j]) {
							if(p+2*H<=ch+blocks[i][j] || ch+blocks[i][j]==cch) {
								hei[i]-=blocks[i][j];
								th-=blocks[i][j];
								blocks[i][j]=0;
								_P("go\n");
							}
							else {
								_P("stop\n");
							}
							goto out;
						}
						else {
							ch+=blocks[i][j];
						}
					}
					_P("miss\n");
					goto out;
					
				}
			}
			_P("miss\n");
			out:
			;
		}
	}
	
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


