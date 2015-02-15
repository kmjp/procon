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

int N,M,NM;
int T[3001],S[3001],NT,pat[3001];
int rm;
int resm[3000];


void solve(int _loop) {
	int i,j,k,resa,resb;
	int a,b,c,d;
	
	GET2(&N,&M);
	NT=0;
	FOR(i,M) {
		T[i]=GETi();
		S[i]=NT;
		FOR(j,T[i]) {
			pat[NT]=GETi();
			if(GETi()==0) pat[NT]*=-1;
			NT++;
		}
	}
	
	ZERO(resm);
	
	//先に1個しか好みが無いのを処理してしまう
	NM=0;
	FOR(i,M) {
		if(T[i]==1 && pat[S[i]]>0) {
			resm[abs(pat[S[i]])]=1;
		}
		else {
			T[NM]=T[i];
			S[NM]=S[i];
			NM++;
		}
	}
	
	i=0;
	M=NM;
	while(i<M) {
		//現状で満足しているか？
		int ok=0;
		int mi=-1;
		FOR(j,T[i]) {
			int type=abs(pat[S[i]+j]);
			int mel=(pat[S[i]+j]>0)?1:0;
			if(mel==1) mi=j;
			if(resm[type]==mel){ ok=1; break;}
		}
		
		if(ok) {
			i++;
		}
		else {
			if(mi==-1) {
				//1にできるものがもうないのでアウト
				_PE("Case #%d: IMPOSSIBLE\n",_loop);
				return;
			}
			//1を１個追加
			resm[abs(pat[S[i]+mi])]=1;
			i=0;
		}
	}
	
	_PE("Case #%d:",_loop);
	FOR(i,N){ _PE(" %d",(resm[i+1]<1)?0:1);}
	_PE("\n");
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



