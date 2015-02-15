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

typedef signed long long s64;
typedef unsigned long long u64;


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

const s64 mm=2*3*5*7;
int L;
int MOD[50][50];
char str[100];
s64 dp[50][50][mm];
s64 dp2[50][mm];

int calcmod(int s,int e) {
	char st[100];
	s64 v;
	int iv=0,i;
	int t=1;
	
	strcpy(st,&str[s]);
	st[e-s]=0;
	sscanf(st,"%lld",&v);
	
	for(i=e-s-1;i>=0;i--) {
		iv += t*(st[i]-'0');
		t = (t*10)%mm;
	}
	iv%=mm;
	
	
	
	//_P("%d %d %s %lld %d\n",s,e,st,v,iv);
	return iv;
	
	
}

void solve(int _loop) {
	int i,j,k,l,x,y;
	s64 res = 0;
	
	GETs(str);
	L=strlen(str);
	ZERO(MOD);
	FOR(i,L) {
		for(j=i+1;j<=L;j++) MOD[i][j]=calcmod(i,j);
	}
	
	if(L==1) {
		int v=MOD[0][1];
		_PE("Case #%d: %d\n",_loop,(v==1)?0:1);
		return;
	}
	
	ZERO(dp);
	ZERO(dp2);
	for(x=L-1;x>=0;x--) {
		dp[x][L][MOD[x][L]]+=1;
		if(x>0) dp[x][L][(mm-MOD[x][L])%mm]+=1;
		
		for(y=L-1;y>=x+1;y--) {
			int m = MOD[x][y];
			
			FOR(i,mm) {
				dp[x][y][(m+i)%mm]+=dp2[y][i];
				if(x>0) dp[x][y][(mm-m+i)%mm]+=dp2[y][i];
			}
		}
		for(y=L;y>=x+1;y--) {
			FOR(i,mm) dp2[x][i]+=dp[x][y][i];
		}
	}
	
	res=0;
	FOR(i,mm) if((i%2==0)||(i%3==0)||(i%5==0)||(i%7==0)) res+=dp2[0][i];
	
	_PE("Case #%d: %lld\n",_loop,res);
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



