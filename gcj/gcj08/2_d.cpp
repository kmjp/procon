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
#else
#define DBG(...)
#define DV(...)
#endif


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

int K,L;
char S[60000];
int con[20][20];
int num[20][20];
int memo[20][20][1<<16];

/*
int perm[20];
int calc() {
	int num,i;
	char pc='*',c;
	
	num=0;
	FOR(i,L) {
		c = S[(i/K)*K + perm[i%K]];
		if(pc!=c) num++;
		pc=c;
	}
	return num;
}
*/

int dfs(int s,int t,int mask) {
	int v,mi;
	if(memo[s][t][mask]==-1) {
		if(mask==(1<<K)-1) {
			memo[s][t][mask] = num[s][t];
		}
		else {
			mi = 99999;
			FOR(v,K) {
				if(mask & (1<<v)) continue;
				mi = min(mi, num[s][v] + dfs(v,t,mask | (1<<v)));
			}
			memo[s][t][mask] = mi;
		}
		//_P("%d %d %x %d\n",s,t,mask,memo[s][t][mask]);
	}
	return memo[s][t][mask];
}

void solve(int _loop) {
	int i,j,k,x,y,result,res;
	double po,l,h;
	
	K=GETi();
	GETs(S);
	L=strlen(S);
	
	if(K==1) {
		res=1;
		FOR(i,L-1) if(S[i]!=S[i+1]) res++;
		goto out;
	}
	
	ZERO(con);
	ZERO(num);
	
	//˜AŒ‹•”
	FOR(x,K) {
		FOR(y,K) {
			con[x][y]=1;
			FOR(i,L/K-1) if(S[i*K+x]!=S[(i+1)*K+y]) con[x][y]++;
			//_P("%d %d %d\n",x,y,con[x][y]);
		}
	}
	
	//•¶Žš“à
	FOR(x,K) {
		FOR(y,K) {
			FOR(i,L/K) if(S[i*K+x]!=S[i*K+y]) num[x][y]++;
			//_P("%d %d %d\n",x,y,num[x][y]);
		}
	}
	
	res=99999;
	MINUS(memo);
	FOR(x,K) {
		FOR(y,K) {
			if(x==y) continue;
			res=min(res,dfs(x,y,(1<<x)|(1<<y)) + con[y][x]);
		}
	}
	
	
	
	
	/*
	FOR(i,K) { perm[i]=i;}
	
	res = L;
	do {
		res = min(res, calc());
	}while(next_permutation(perm,perm+K));
	*/
out:
	_PE("Case #%d: %d\n",_loop,res);
	
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



