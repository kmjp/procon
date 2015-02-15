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

int T,NA,NB;
int S[301],E[301];
int vis[301];


void solve(int _loop) {
	int i,j,k,resa,resb;
	int a,b,c,d;
	
	T=GETi();
	GET2(&NA,&NB);
	FOR(i,NA) {
		scanf("%d:%d %d:%d",&a,&b,&c,&d);
		S[i]=a*60+b;
		E[i]=c*60+d;
	}
	FOR(i,NB) {
		scanf("%d:%d %d:%d",&a,&b,&c,&d);
		S[i+100]=a*60+b;
		E[i+100]=c*60+d;
	}
	
	ZERO(vis);
	resa=resb=0;
	while(1) {
		//ŠJŽn‚ð‹‚ß‚é
		int s=999999;
		k=0;
		FOR(i,NA) if(s>S[i] && !vis[i]){ s=S[i]; k=i;}
		FOR(i,NB) if(s>S[i+100] && !vis[i+100]){ s=S[i+100]; k=i+100;}
		if(s==999999) break;
		if(k<100) resa++;
		else resb++;
		
		while(1) {
			vis[k]=1;
			int nt=E[k]+T;
			s=999999;
			int nk=0;
			if(k>=100) {
				FOR(i,NA) if(s>S[i] && nt<=S[i] && !vis[i]){ s=S[i]; nk=i;}
			}
			else {
				FOR(i,NB) if(s>S[i+100] && nt<=S[i+100] && !vis[i+100]){ s=S[i+100]; nk=i+100;}
			}
			
			if(s==999999) break;
			k=nk;
		}
	}
	
	_PE("Case #%d: %d %d\n",_loop,resa,resb);
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



