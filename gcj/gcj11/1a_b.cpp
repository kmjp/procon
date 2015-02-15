/* largeは20分ぐらいかかる */

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


int N,M;
int Ds[11];
char D[11][10000][15];
int Dl[11][10000];

char L[101][27];
char DD[10000][12];
char results[100];
int revscore[27];
int most,str;
int ng[11][10000];

int calcscore(int len,int w) {
	int i,j,cost;
	int skip[10000];
	int chrs[27];
	int cand[27];
	int pos;
	int rs,ok;
	char tar,nt;
	cost=0;
	int ml[10000],max;
	int mapl[10000],nmapl[10000];
	int ms,nms;
	
	//文字の持ってるリスト
	ZERO(ml);
	FOR(i,Ds[len]) FOR(j,len) ml[i] |= 1<<(DD[i][j]-'a');
	max='a';
	FOR(j,len) if(max < DD[w][j]) max=DD[w][j];
	if(max-'a' < most) return -1;
	if(ng[len][w]) return -1;
	
	ZERO(skip);
	ZERO(chrs); //確定済み文字

	ms=Ds[len];
	FOR(i,Ds[len]) mapl[i]=i;
	
	for(nt='a';nt<='z';nt++) {
		if(cost + 'z' - nt + 1 < most) return -1;
		j=0;
		// ターゲットの文字は確定か？
		if(1<<(nt-'a') > ml[w]) break;
		
		//ターゲットの文字を持つものはいるか？
		ok=0;
		FOR(i,ms) {
			if((ml[mapl[i]] & (1<<(nt-'a')))){
				ok++;
				break;
			}
		}
		if(ok==0) continue;
		if((ml[w]&(1<<(nt-'a')))==0) cost++;
		
		//オープンされる
		nms=0;
		FOR(i,ms) {
			ok=1;
			if(mapl[i]!=w) {
				FOR(j,len) {
					if(DD[w][j]!=nt && DD[mapl[i]][j]==nt){ ok=0; break;}
					if(DD[w][j]==nt && DD[mapl[i]][j]!=nt){ ok=0; break;}
				}
			}
			if(ok) {
				nmapl[nms++]=mapl[i];
			}
			else {
				//ng[len][mapl[i]]=1;
			}
		}
		ms=nms;
		memcpy(mapl,nmapl,ms*4);
		
	}
	
	return cost;
}

int proc(int len) {
	int i,score,j;
	
	if(Ds[len]==0) return 0;
	
	//文字順並べ替え
	ZERO(DD);
	FOR(i,Ds[len]) {
		FOR(j,len) {
			DD[i][j] = revscore[D[len][i][j]-'a']+'a';
		}
		DD[i][len]=0;
	}
	
	FOR(i,Ds[len]) {
		if(Ds[len]==1) {
			score=0;
		}
		else {
			
			
			score=calcscore(len,i);
		}
		if(score>most) {
			most=score;
			strcpy(results,D[len][i]);
			str=Dl[len][i];
		}
		else if(score==most) {
			if(str > Dl[len][i]) {
				strcpy(results,D[len][i]);
				str=Dl[len][i];
			}
		}
		//_P("%d %d %d %s %d\n",most,str,score,D[len][i],Dl[len][i]);
	}
	
	return 0;
}

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	double br,tb1,tb2,start,end;
	char list[1000],ts[2],ress[1000];
	int gs,ge,ll,suc;
	
	ZERO(Ds);
	ZERO(D);
	ZERO(L);
	GET2(&N,&M);
	
	FOR(i,N) {
		GETs(list);
		Dl[strlen(list)][Ds[strlen(list)]]=i;
		strcpy(D[strlen(list)][Ds[strlen(list)]++],list);
	}
	FOR(i,M) {
		GETs(L[i]);
	}
	
	_PE("Case #%d:",_loop);
	FOR(k,M) {
		ZERO(ng);
		FOR(i,26) {
			revscore[L[k][i]-'a'] = i;
		}
		
		most=-1;
		FOR(i,11) {
			proc(i);
		}
		_PE(" %s",results);
	}
	_PE("\n",_loop);
	
	
	
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



