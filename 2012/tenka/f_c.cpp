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

int N;
int HP,ATK,REC;
int DP[40][101];

int DP2[101][101][101];
int SDP[101][151],EDP[101][151];
deque<int> deq;

int key(int mhp,int ehp, int nb) {
	return mhp*40000+ehp*200+nb;
}
void do_dp2() {
	int x,y,z;

	MINUS(DP2);
	MINUS(EDP);
	deq.clear();
	FOR(x,101) {
		FOR(y,151) {
			if(SDP[x][y]==-1) continue;
			//わざわざ悪いのでやる必要はない
			for(z=x+1;z<=100;z++) if(SDP[z][y]!=-1 && SDP[z][y]<=SDP[x][y]) break;
			if(z<101) continue;
			for(z=y+1;z<=150;z++) if(SDP[x][z]!=-1 && SDP[x][z]<=SDP[x][y]) break;
			if(z<151) continue;
			DP2[x][HP][y] = SDP[x][y];
			deq.push_back(key(x,HP,y));
		}
	}
	
	while(!deq.empty()) {
		int mkey = deq.front();
		deq.pop_front();
		int myhp = mkey / 40000;
		int ehp = (mkey / 200)%200;
		int nb = mkey % 200;
		int turn = DP2[myhp][ehp][nb];
		//_P("%d -> %d %d %d %d\n",mkey,myhp,ehp,nb,turn);
		
		int nmhp,nehp;
		//Aを選択
		nmhp = myhp-ATK;
		nehp = ehp-5;
		if(nmhp > 0) {
			if(nehp<=0) {
				//撃破
				if(EDP[nmhp][0]==-1 || EDP[nmhp][0]>turn+1){
					//_P("A done! %d %d\n",nmhp,turn+1);
					EDP[nmhp][0]=turn+1;
				}
			}
			else {
				nehp += REC;
				if(nehp>HP) nehp=HP;
				if(DP2[nmhp][nehp][0]==-1 || turn+1<DP2[nmhp][nehp][0]) {
					DP2[nmhp][nehp][0]=turn+1;
					//_P("A : %d %d %d ->%d %d %d : %d (%d)\n",myhp,ehp,nb,nmhp,nehp,0,turn+1,key(nmhp,nehp,0));
					deq.push_back(key(nmhp,nehp,0));
				}
			}
		}
		
		//Bを選択
		nmhp = myhp-ATK;
		nehp = ehp-(nb+1);
		if(nmhp > 0) {
			if(nehp<=0) {
				//撃破
				if(EDP[nmhp][nb+1]==-1 || EDP[nmhp][nb+1]>turn+1){
					//_P("B done! %d %d %d\n",nmhp,nb+1,turn+1);
					EDP[nmhp][nb+1]=turn+1;
				}
			}
			else {
				nehp += REC;
				if(nehp>HP) nehp=HP;
				if(DP2[nmhp][nehp][nb+1]==-1 || turn+1<DP2[nmhp][nehp][nb+1]) {
					DP2[nmhp][nehp][nb+1]=turn+1;
					//_P("B : %d %d %d ->%d %d %d : %d (%d)\n",myhp,ehp,nb,nmhp,nehp,0,turn+1,key(nmhp,nehp,nb+1));
					deq.push_back(key(nmhp,nehp,nb+1));
				}
			}
		}
		//Cを選択
		nmhp = myhp-ATK;
		nehp = ehp;
		if(nmhp > 0) {
			nmhp += 50;
			if(nmhp>100) nmhp=100;
			nehp += REC;
			if(nehp>HP) nehp=HP;
			if(DP2[nmhp][nehp][0]==-1 || turn+1<DP2[nmhp][nehp][0]) {
				DP2[nmhp][nehp][0]=turn+1;
					//_P("C : %d %d %d ->%d %d %d : %d (%d)\n",myhp,ehp,nb,nmhp,nehp,0,turn+1,key(nmhp,nehp,0));
				deq.push_back(key(nmhp,nehp,0));
			}
		}
	}
	
}


void solve() {
	s64 res;
	int f,r,i,x,y,n,m,v1,v2;
	
	//combination
	N=GETi();
	
	MINUS(EDP);
	EDP[100][0]=0;
	FOR(i,N){
		GET3(&HP,&ATK,&REC);
		memmove(SDP,EDP,sizeof(SDP));
		do_dp2();
	}
	
	m=99999999;
	FOR(x,101) {
		FOR(y,151) {
			if(EDP[x][y]!=-1 && EDP[x][y]<m) m=EDP[x][y];
		}
	}
	if(m==99999999) m=-1;
	
	_P("%d\n",m);
	
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



