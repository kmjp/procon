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
#define SIGN(n) (n==0?0:(n>0 ? 1 : -1))

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int H,W,D;
char maps[40][40];
int gcm[51][51];
int mx,my;

int check(int dx,int dy) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei,stx,sty,step;
	double br,tb1,tb2,start,end;
	int smx,smy,lmx,lmy,lcm,ld,crx,cry,dist,disx,disy,sgx,sgy;
	int rmx,rmy,match;
	
	//proceed dy times
	for(step=1;step<=D;step++) {
		disx = step*dx;
		disy = step*dy;
		if(disx*disx+disy*disy > D*D) return 0;
		rmx = abs(disx)%(2*(W-2));
		rmy = abs(disy)%(2*(H-2));
		
		match=0;
		if(rmx==0) match++;
		else {
			if((dx > 0) && rmx==(W-mx)*2-3) match++;
			if((dx < 0) && rmx==mx*2-1) match++;
		}
		
		if(rmy==0) match++;
		else {
			if((dy > 0) && rmy==(H-my)*2-3) match++;
			if((dy < 0) && rmy==my*2-1) match++;
		}
		
		if(match==2){
			//_P("hit! %d %d %d %d\n",dx,dy,disx,disy);
			return 1;
		}
		
		
	}
	
	return 0;
	
}

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei;
	double br,tb1,tb2,start,end;
	int dx,dy;
	
	result = 0;
	ZERO(maps);
	GET3(&H,&W,&D);
	
	FOR(i,H) {
		GETs(maps[i]);
	}
	
	FOR(y,H) {
		FOR(x,W) {
			if(maps[y][x]=='X') {
				mx=x;my=y;
				maps[y][x]='.';
			}
		}
	}
	
	//left
	x = mx;
	while(x>=0) {
		if(maps[my][x]=='#') break;
		x--;
	}
	if(x>=0 && (mx-x)*2-1 <= D) result++;
	
	//right
	x = mx;
	while(x<W) {
		if(maps[my][x]=='#') break;
		x++;
	}
	if(x<W && (x-mx)*2-1 <= D) result++;
	
	//up
	y = my;
	while(y>=0) {
		if(maps[y][mx]=='#') break;
		y--;
	}
	if(y>=0 && (my-y)*2-1 <= D) result++;
	
	//down
	y = my;
	while(y<H) {
		if(maps[y][mx]=='#') break;
		y++;
	}
	if(y<H && (y-my)*2-1 <= D) result++;
	
	for(dx=1;dx<=50;dx++) {
		for(dy=1;dy<=50;dy++) {
			if(gcm[dx][dy]>1) continue;
			if(dx*dx+dy*dy>D*D) continue;
			result += check(dx,dy);
			result += check(dx,-dy);
			result += check(-dx,dy);
			result += check(-dx,-dy);
		}
	}
	
	
	_PE("Case #%d: %d\n",_loop,result);
}

void init() {
	int i,j,k;
	
	ZERO(gcm);
	for(i=1;i<=50;i++) {
		for(j=i;j<=50;j++) {
			gcm[i][j]=gcm[j][i]=1;
			for(k=j;k>=2;k--) {
				if((i%k)==0 && (j%k)==0){
					gcm[i][j]=gcm[j][i]=k;
					break;
				}
			}
		}
	}
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



