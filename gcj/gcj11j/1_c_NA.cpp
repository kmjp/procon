/* 未正解 */

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
char A[51],B[51],resc[51],tmp[51];
int ast;
int mapa[51][51];

void docmp(char* sa,char* sb) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,isb;
	int Bpos,Opos,Btim,Otim,walk,tim;
	int total,a,b,target,d1,d2,d3;
	int la,lb,ok2,nm;
	
	la=strlen(sa);
	lb=strlen(sb);
	
	ZERO(mapa);
	//A[x]からy文字と一致する文字列があるか？で探す
	for(x=0;x<la;x++) {
		for(y=1;y<=la-x;y++) {
			//B[i]からy文字を検索
			//ただしxが先頭なら先頭だけチェック
			//ただしxが終端なら終端だけチェック
			ok2=1;
			for(i=0;i<=lb-y;i++) {
				if(x==0 && i>0) break;
				if(x==la-y && i!=lb-y) continue;
				
				//_P("\n(%d %d %d %d)",i,lb,y,ok2);
				nm=0;
				for(j=0;j<y;j++) {
					//_P("([%d][%d]%d%c%c)",x+j,i+j,j,sa[x+j],sb[i+j]);
					if(sa[x+j]!=sb[i+j]){
						nm=1;
						break;
					}
				}
				if(nm==0){
					ok2=0;
					break;
				}
			}
			mapa[x][y]=ok2;
			//printf("[%d][%d]%d ",x,y,ok2);
			
			if(ok2) {
				nm=y;
				if(x>0) nm++;
				if(x<la-y) nm++;
				ok2=0;
				if(nm<strlen(resc) || strlen(resc)==0) ok2=1;
				if(nm==strlen(resc) && nm-y < ast) ok2=1;
				i=0;
				for(j=0;j<51;j++) tmp[j]=0;
				if(x>0) tmp[i++]='*';
				for(j=0;j<y;j++) {
					tmp[i++]=sa[x+j];
				}
				if(x<la-y) tmp[i++]='*';
				tmp[i+1]=0;
				
				if(ok2==0 && nm==strlen(resc) && nm-y == ast) {
					if(strcmp(resc,tmp) > 0) ok2=1;
				}
				if(ok2) {
					ast = nm-y;
					for(j=0;j<51;j++) resc[j]=tmp[j];
					//printf("(%d,%d)%s ",nm,nm-y,resc);
					
				}
				
			}
			
		}
		//printf("\n",ok2);
	}
}


void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,isb;
	int Bpos,Opos,Btim,Otim,walk,tim;
	int total,a,b,target,d1,d2,d3;
	int la,lb,ok2,nm;
	
	GETs(A);
	GETs(B);
	
	ast=0;
	resc[0]=0;
	
	docmp(A,B);
	//docmp(B,A);
	
	_PE("Case #%d: %s\n",_loop,resc);
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



