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
int F[10002], T[10002];
char str[3000];
char str2[3000];
int nl;
int first;
int w[500];

int ok[100000];
int nok[100000];

void chg(char* s) {
	while(strlen(s)) {
		if(*s !='g') {
			s++;
			continue;
		}
		else {
			strcpy(s,s+5);
		}
	}
}

void solve() {
	int m,d,i,j,no;
	int ns=0;
	int s[100];
	char* c;
	
	N=GETi();
	M=GETi();
	FOR(i,M){
		F[i]=GETi()-1;
		T[i]=GETi()-1;
	}
	GETs(str);
	//count;
	c=str;
	nl=1;
	while(*c=='"') {
		c++;
		nl++;
	}
	c+=5;
	sscanf(c,"%d%n",&first,&i);
	c+=i;
	if(*c=='w') {
		w[0]=1;
		c++;
	}
	else w[0]=0;
	
	
	if(nl>1) {
		i=1;
		while(i<nl && *c=='"') {
			c++;
			if(*c=='w') {
				w[i]=1;
				c++;c++;
			}
			else w[i]=0;
			i++;
		}
	}
	
	first--;
	ZERO(ok);
	if(w[0]==0) {
		no = 0;
		if(first>=0 && first<N) no=1;
		FOR(i,N) ok[i]=no;
		FOR(i,M) {
			if(T[i]==first) ok[F[i]]=0;
		}
	}
	else {
		FOR(i,M) {
			if(T[i]==first) ok[F[i]]=1;
		}
	}
	
	
	for(i=1;i<nl;i++){
		ZERO(nok);
		if(w[i]==0) {
			no=0;
			FOR(j,N) {
				if(ok[j]) no++;
			}
			FOR(j,N) nok[j]=no;
			FOR(j,M) {
				if(ok[T[j]]) nok[F[j]]--;
				if(nok[F[j]]<0) nok[F[j]]=0;
			}
		}
		else {
			FOR(j,M) {
				if(ok[T[j]]) nok[F[j]]++;
			}
		}
		
		memmove(ok,nok,sizeof(ok));
		
	}
	
	no=0;
	FOR(j,N) if(ok[j]) no++;
	
	_P("%d\n",no);
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



