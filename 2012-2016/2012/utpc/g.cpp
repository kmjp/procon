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

int N,K,L,M;
char str[30];


void solve() {
	int x,y,i,j,rr,TM,nc;
	int tx,ty;
	int dp[27][27][500];
	ll p,cch;
	
	N=GETi();
	K=GETi();
	GETs(str);
	
	L=strlen(str);
	M=str[0]-'a';
	FOR(i,L) if(str[i]<str[0]) M--;
	
	p=0;
	FOR(x,N-L+1) {
		int cp=K-L;
		FOR(i,L) if(str[i]<str[0]) cp -= (N-x-i);
		if(cp<0 || M<0) continue;
		// N-L‚±‚©‚çMŒÂ‘I‚ñ‚ÅcpŒÂ
		ZERO(dp);
		dp[0][M][cp]=1;
		
		FOR(y,N) {
			FOR(i,M+1) FOR(j,cp+1) {
				if((y<x || y>=x+L) && i>0 && j>=N-y)
					dp[y+1][i-1][j-(N-y)]=(dp[y+1][i-1][j-(N-y)]+dp[y][i][j])%1000000007;
				dp[y+1][i][j]=(dp[y+1][i][j]+dp[y][i][j])%1000000007;
			}
		}
		p += dp[N][0][0];
	}
	
	// MŒÂ‚Ì•À‚×•û
	FOR(i,M) {
		p=(p*(i+1))%1000000007;
	}
	
	//str[0]‚æ‚è‘å‚«‚¢•¶Žš‚Ì•À‚×•û
	x=(N-1)-(str[0]-'a');
	FOR(i,L) if(str[i]>str[0]) x--;
	FOR(i,x) {
		p=(p*(i+1))%1000000007;
	}
	
	_P("%lld\n",p);
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


