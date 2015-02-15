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


int M;
int C,W,A,B;

int nument;
int start[300];
int num[300];

int fn;
int fstart[300];
int fnum[300];

int pn;
int pstart[300];
int pnum[300];


void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,isb;
	int Bpos,Opos,Btim,Otim,walk,tim;
	int total,a,b,target,d1,d2,d3;
	GET3(&M,&C,&W);
	
	nument = 1;
	start[0]=1;
	num[0]=M;
	
	FOR(i,C) {
		GET2(&A,&B);
		//シャッフルで上に来る者
		
		fn=pn=0;
		total = 1;
		FOR(j,nument){
			
			if(total+num[j]-1 < A || A+B-1 < total ) {
				//全部シャッフル範囲外
				pstart[pn] = start[j];
				pnum[pn] = num[j];
				pn++;
				//_P("%d\n",__LINE__);
			}
			else if(A <= total && total+num[j]-1 <= A+B-1) {
				//全部シャッフル範囲内
				fstart[fn] = start[j];
				fnum[fn] = num[j];
				fn++;
				//_P("%d\n",__LINE__);
			}
			else {
				//シャッフルの左側
				//_P("split type %d %d %d %d (%d-%d)\n",A,B,total,num[j],start[j],start[j]+num[j]-1);
				
				if(total < A) {
					pstart[pn] = start[j];
					pnum[pn] = A - total;
					//_P("left %d %d\n",pstart[pn],pnum[pn]);
					pn++;
					//_P("%d\n",__LINE__);
				}
				
				//シャッフルの右側
				if(A+B-1 < total+num[j]-1) {
					pnum[pn] = total+num[j]-(A+B);
					pstart[pn] = start[j]+num[j]-pnum[pn];
					//_P("right %d %d\n",pstart[pn],pnum[pn]);
					pn++;
					//_P("%d\n",__LINE__);
				}
				//シャッフル範囲を絞る
				a=A; b=B;
				if(a < total){ b -= total-a; a=total; }
				if(a+b-1 > total+num[j]-1){ b=total+num[j]-a;}
				fstart[fn]=start[j]+a-total;
				fnum[fn]=b;
				//_P("shuffle %d %d\n",fstart[fn],fnum[fn]);
				fn++;
				
			}
			
		next:
			total += num[j];
		}
		
		FOR(j,fn) {
			start[j] = fstart[j];
			num[j] = fnum[j];
		}
		FOR(j,pn) {
			start[fn+j] = pstart[j];
			num[fn+j] = pnum[j];
		}
		nument = fn+pn;
		total=0;
		FOR(j,nument) {
			total+=num[j];
			//_P("Current : %2d:%2d %2d : ",j,start[j],num[j],start[j]+num[j]-1);
			//FOR(k,num[j]) {_P("%d ",start[j]+k); }
			//_P("\n");
		}
	}
	
	FOR(j,nument) {
		if(W>num[j]) {
			W-=num[j];
		}
		else {
			result = start[j] + W-1;
			break;
		}
	}
	
	
	_PE("Case #%d: %d\n",_loop,result);
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



