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
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {
	int i;
	FOR(i,rep) p[i]=val;
}

#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

int R,C,F;
int d[10];
char line[1000];
char data[60][60];
int state[50][50][50][50];
int fallable[50][50];


int dig(int y,int x,int left,int right) {
	int i,j,lst,rst,lh,rh,ok,minst=9999,v,fx,lst2;
	if(y>=R-1) {
		state[x][y][left][right]=0;
	}
	if(state[x][y][left][right]>=0)
		return state[x][y][left][right];
		
	
	
	lh=0;
	lst=x;
	while(1) {
		if(lst==0 || (data[y][lst-1]=='#' && lst-1<left)) {
			break;
		}
		if(data[y+1][lst-1]=='.'){
			lh=1;
			break;
		}
		lst--;
	}
	
	rh=0;
	rst=x;
	while(1) {
		if(rst==C-1 || (data[y][rst+1]=='#' && rst+1>right)) {
			break;
		}
		if(data[y+1][rst+1]=='.'){
			rh=1;
			break;
		}
		rst++;
	}
	
	//Šù‚É’Ê‚Á‚½‚©H
	FOR2(i,lst,rst+1) {
		if(state[i][y][left][right]>=0)
			break;
	}
	if(i<=rst) {
		FOR2(j,lst,rst+1) {
			state[j][y][left][right] = state[i][y][left][right];
		}
		return state[x][y][left][right];
	}
	
	//—Ž‰º
	ok=0;
	//—Ž‰º‚Å“Í‚­
	if((lh==1 && fallable[lst-1][y]>=R) || 
	   (rh==1 && fallable[rst+1][y]>=R)){
		minst=0;
		goto minst_found;
	}
	//“Í‚©‚È‚¢
	if(lh==1 && fallable[lst-1][y]>y ) {
		v=dig(fallable[lst-1][y],lst-1,lst-1,lst-1);
		if(v<minst) minst=v;
		if(minst==0) goto minst_found;
	}
	if(rh==1 && fallable[rst+1][y]>y ) {
		v=dig(fallable[rst+1][y],rst+1,rst+1,rst+1);
		if(v<minst) minst=v;
	}
	if(minst==0) goto minst_found;
	
	//“®‚¯‚È‚¢
	if(lst==rst) {
		goto minst_found;
	}
	
	//1ŒÂŒ@‚ê‚Î“Í‚­
	for(fx=lst;fx<=rst;fx++) {
		if(fallable[fx][y]>=R) {
			minst=1;
			goto minst_found;
		}
	}
	
	//1ŒÂŒ@‚é‚Æ‚Qƒ}ƒX—Ž‰º‚·‚é
	if(lst!=rst) {
		for(fx=lst;fx<=rst;fx++) {
			if(fallable[fx][y]>y+1) {
				v = 1 + dig(fallable[fx][y],fx,fx,fx);
				if(v<minst) minst=v;
				if(minst==1) goto minst_found;
			}
		}
	}
	
	//1ƒ}ƒX‚µ‚©—Ž‰º‚Å‚«‚È‚¢
	if(lst!=rst) {
		for(fx=lst;fx<=rst;fx++) {
			if(fallable[fx][y]==y+1) {
				//‰E‚©‚ç~‚è‚é
				if(fx<rst) {
					for(lst2=lst;lst2<=fx;lst2++) {
						v = (1+fx-lst2) + dig(y+1,fx,lst2,fx);
						if(v<minst) minst=v;
					}
					if(minst==1) goto minst_found;
				}
				//¶‚©‚ç~‚è‚é
				if(fx>lst) {
					for(lst2=rst;lst2>=fx;lst2--) {
						v = (1+lst2-fx) + dig(y+1,fx,fx,lst2);
						if(v<minst) minst=v;
					}
					if(minst==1) goto minst_found;
				}
			}
		}
	}
	
	state[x][y][left][right]=minst;
	//_E("ok found %d %d [%d %d] [%d %d] [%d %d]%d\n",x,y,left,right,lst,rst,lh,rh,minst);
	return minst;
minst_found:
	//_E("found %d %d [%d %d] [%d %d] [%d %d]%d\n",x,y,left,right,lst,rst,lh,rh,minst);
	FOR2(j,lst,rst+1) {
		state[j][y][left][right] = minst;
	}
	return minst;
}


void solve(int _loop) {
	int i,result,x,y;
	GET3(&R,&C,&F);
	
	ZERO(data);
	MINUS(state);
	FOR(i,R) GETs(data[i]);
	ZERO(fallable);
	FOR(y,R) {
		FOR(x,C) {
			for(i=y+2;i<=y+1+F;i++) {
				if(i>=R){fallable[x][y]=R; break;}
				if(data[i][x]=='#'){fallable[x][y]=i-1; break;}
			}
		}
	}
	
	result = dig(0,0,0,0);
	if(result<9999) {
		_PE("Case #%d: Yes %d\n",_loop,result);
	}
	else {
		_PE("Case #%d: No\n",_loop);
	}
	
	
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



