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

typedef signed long long ll;
typedef unsigned long long ull;

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

vector<string> SL;
// 公式からダウンロード
const char* hoge[] = {
"a",
"aa",
"" };


void solve(int _loop) {
	int i,j,x,y,ne=0;
	int NP,TP,PP;
	char str[5000];
	int DP[5000][6];
	int L;
	
	GETs(str);
	L=strlen(str);
	FOR(x,5000) FOR(y,6) DP[x][y]=99999;
	DP[0][0]=0;
	
	FOR(i,L) {
		int ok=0;
		FOR(x,SL.size()) {
			int ss = SL[x].size();
			if(i+ss>L) continue;
			
			int st=-1,ed=-1,num=0;
			FOR(y,ss) {
				if(str[i+y]!=SL[x][y]) {
					if(num && y-ed<4) {
						num=-1;
						break;
					}
					if(st==-1) st=y+1;
					ed=y+1;
					num++;
				}
			}
			
			if(num==-1) continue;
			if(num==0) {
				FOR(y,6) DP[i+ss][max(0,y-ss)] = min(DP[i+ss][max(0,y-ss)], DP[i][y]);
			}
			else {
				FOR(y,6) if(st>=y) DP[i+ss][max(0,5+ed-ss)] = min(DP[i+ss][max(0,5+ed-ss)], num+DP[i][y]);
			}
		}
		//_P("%d %d %d %d %d %d %d\n",DP[i][0],DP[i][1],DP[i][2],DP[i][3],DP[i][4],DP[i][5],ok);
	}
	
	int mi=99999;
	FOR(y,6) mi=min(mi,DP[L][y]);
	_PE("Case #%d: %d\n",_loop,mi);
	
}

void init() {
	for(int i=0;strlen(hoge[i]);i++) SL.push_back(string(hoge[i]));
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



