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
#define _Dm(fmt) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__)
#define _D(fmt, ...) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
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

string res,ma;
int N,K;
vector<int> FK;
int NK[201];
vector<int> key[201];

int sta[201];
map<int,int> memo;


int dfs(int mask) {
	int i,j,x,y,d;
	int kk[201];
	ZERO(kk);
	
	if(memo.find(mask)!=memo.end()) return memo[mask];
	if(mask==(1<<N)-1) {
		FOR(i,N) {
			_PE(" %d",sta[i]);
		}
		_PE("\n");
		return 1;
	}
	
	FOR(i,K) kk[FK[i]]++;
	d=0;
	FOR(i,N) if(mask & (1<<i)) {
			d++;
			kk[NK[i]]--;
			FOR(j,key[i].size()) kk[key[i][j]]++;
	}
	
	FOR(i,N) if(!(mask & (1<<i)) && kk[NK[i]]>0) {
		sta[d]=i+1;
		if(dfs(mask | (1<<i))==1) return memo[mask]=1;
	}
	
	return memo[mask]=0;
}

void solve(int _loop) {
	int i,x,y;
	
	GET2(&K,&N);
	FK.clear();
	FOR(i,K) FK.push_back(GETi()-1);
	char s[300];
	ZERO(s);
	FOR(i,N) {
		s[i]=255;
		NK[i]=GETi()-1;
		key[i].clear();
		y=GETi();
		FOR(x,y) key[i].push_back(GETi()-1);
	}
	
	memo.clear();
	ZERO(sta);
	_PE("Case #%d:",_loop);
	if(dfs(0)==0) {
		_PE(" IMPOSSIBLE\n",_loop);
	}
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
	
	GET1(&loops);
	gets(tmpline);
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL);
		solve(loop);
		gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		_E("                                     time: %lld ms\n",span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



