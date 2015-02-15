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
unsigned long long K;
unsigned long long C[101],T[101];
int S[101];
int nf;
unsigned long long fs[300],fl[300];

int nnf;
unsigned long long nfs[300],nfl[300];

void solve(int _loop) {
	int i,j,k,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	double br,tb1,tb2,start,end;
	char list[1000],ts[2];
	int gs,ge,ll,suc;
	unsigned long long result;
	
	N=GETi();
	scanf("%lld",&K);
	FOR(i,N) {
		scanf("%lld",&C[i]);
		scanf("%lld",&T[i]);
		scanf("%d",&S[i]);
		//_P("%lld %lld %d\n",C[i],T[i],S[i]);
	}
	
	result=0;

	nf = 1;
	fs[0]=1;
	fl[0]=K;
	
	while(1) {
		//ˆê”Ô‚¢‚¢•¨ŒŸõ
		j=-1;
		FOR(i,N) {
			if(C[i]==0) continue;
			if(j==-1){ j=i; continue;}
			
			if(S[i]>S[j]) j=i;
			else if(S[i]==S[j] && T[i]>T[j]) j=i;
		}
		if(j==-1) break;
		
		//–¢—ˆ‚©‚ç‡‚Éˆù‚ÝŠ±‚·
		nnf=0;
		for(i=nf-1;i>=0;i--) {
			if(fs[i]>T[j]) {
				//‚±‚ÌŠúŠÔ‚Í•…‚é‚Ì‚Å‘ÎÛŠO
				nfs[nnf]=fs[i];
				nfl[nnf]=fl[i];
				//_P("new %d :: %d %lld-%lld\n",__LINE__,nnf,nfs[nnf],nfs[nnf]+nfl[nnf]-1);
				nnf++;
				continue;
			}
			
			if(fs[i]+fl[i] > T[j]) {
				//ŠúŠÔ‚Ì“r’†‚Å•…‚é
				nfs[nnf]=T[j]+1;
				nfl[nnf]=fs[i]+fl[i]-(T[j]+1);
				//_P("new %d :: %d %lld-%lld\n",__LINE__,nnf,nfs[nnf],nfs[nnf]+nfl[nnf]-1);
				nnf++;
				fl[i]=T[j]+1-fs[i];
			}
			
			if(fl[i] > C[j]) {
				result += C[j]*S[j];
				nfs[nnf]=fs[i];
				nfl[nnf]=fl[i]-C[j];
				//_P("new %d :: %d %lld-%lld\n",__LINE__,nnf,nfs[nnf],nfs[nnf]+nfl[nnf]-1);
				nnf++;
				C[j]=0;
			}
			else {
				//‹æŠÔ“à‘S•”
				result += fl[i]*S[j];
				C[j]-=fl[i];
			}
		}
		//‚ ‚Ü‚Á‚Ä‚à‚¢‚ç‚È‚¢
		C[j]=0;
		//_PE("current %d: %lld\n",j,result);
		
		//‹t‡‚É–ß‚·
		FOR(i,nnf) {
			fs[i]=nfs[nnf-1-i];
			fl[i]=nfl[nnf-1-i];
			//_P("[%d] %d:: %lld-%lld\n",__LINE__,i,fs[i],fs[i]+fl[i]-1);
		}
		nf=nnf;
		
	}
	
	
	_PE("Case #%d: %lld\n",_loop,result);
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



