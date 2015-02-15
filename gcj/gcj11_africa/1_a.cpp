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


int N;
char str[1000][20];
long long num[1000];
long long table[14];
long long th = 33333333333LL;

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,isb,left,rep;
	double br,tb1,tb2,start,end;
	
	char tmp[1000];
	
	GET1(&N);
	ZERO(str);
	
	FOR(i,N) {
		GETs(&str[i]);
	}
	
	//sort
	FOR(i,N) {
		FOR2(j,i+1,N) {
			if(strcmp(str[i],str[j]) > 0) {
				strcpy(tmp,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],tmp);
			}
		}
	}
	
	FOR(i,N) {
		j=strlen(str[i]);
		num[i]=0;
		FOR2(k,2,j) {
			//_P("%c ",str[i][k]);
			num[i] += (str[i][k]-'0')*table[10-(k-2)];
		}
		//_P("%s %lld %lld\n",str[i],num[i],th);
		
	}
	
	_PE("Case #%d:\n",_loop);
	rep = 0;
	while(rep++ < 1000) {
		FOR(i,N) {
			if(num[i]<0) continue;
			
			
			if(num[i]>th && num[i]<=th*2) {
				_PE("%s\n",str[i],rep);
				num[i]=-1;
			}
			else if(num[i]>th*2) {
				//_P("**%s %lld %lld\n",str[i],num[i],(100000000000LL - num[i]));
				num[i] = (100000000000LL - num[i])*3;
				//_P("**ok %lld\n",num[i]);
			}
			else if(num[i] <= th) {
				num[i] *= 3;
			}
			
		}
	}
	
	FOR(i,N) {
		if(num[i]>=0) _PE("%s\n",str[i]);
	}
	
	
	//_PE("Case #%d: %d\n",_loop,result);
}

void init() {
	int i,j;
	table[0]=1;
	FOR(i,12) table[i+1] = table[i]*10;
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



