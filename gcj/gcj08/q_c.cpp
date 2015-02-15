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

#define EPS (1e-7)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

double f,R,t,r,g,PI,tr;

double segment(double nx,double ny) {
	double fx,fy,fx2,fy2,fx3;
	double deg;
	fx=nx+g-2*f;
	fy=ny+g-2*f;
	
	if(fx*fx+fy*fy <= tr*tr) return (g-2*f)*(g-2*f);
	
	//nx‚ªny‚æ‚è‘å‚«‚¢‚Ì‚ÅA‰~‚ÌŽü‚è‚Í0`45“x‚Ü‚ÅA‚æ‚Á‚Ä
	//(nx,fy)‚ª‰~‚ÌŠO‚Å(fx,xy)‚ª‰~‚Ì’†‚É‚È‚é‚±‚Æ‚Í‚È‚¢
	
	//‰Eã‚ª‰~‚ÌŠO
	if(nx*nx+fy*fy<=tr*tr) { //¶ã‚ª‰~‚Ì’†
		if(fx*fx+ny*ny<=tr*tr) { //‰E‰º‚ª‰~‚Ì’†
			//ã‚ÌŒ‡‚¯‚½“_
			fx2 = sqrt(tr*tr-fy*fy);
			//‰E‚ÌŒ‡‚¯‚½“_
			fy2 = sqrt(tr*tr-fx*fx);
			
			deg = atan2(fy,fx2)-atan2(fy2,fx);
			return deg*tr*tr/2 - (fy*fx-fy2*fx2)/2 + (fy-ny)*(fx-nx)-(fy-fy2)*(fx-fx2)/2;
		}
		else { //‰E‰º‚ª‰~‚ÌŠO
			//ã‚ÌŒ‡‚¯‚½“_
			fx2 = sqrt(tr*tr-fy*fy);
			//‰º‚ÌŒ‡‚¯‚½“_
			fx3 = sqrt(tr*tr-ny*ny);
			deg = atan2(fy,fx2)-atan2(ny,fx3);
			return deg*tr*tr/2 - (fy*fx3-ny*fx2)/2 + (fy-ny)*(fx2+fx3-2*nx)/2;
		}
	}
	
	//¶ã‚à‰E‰º‚à‰~‚ÌŠO
	fy = sqrt(tr*tr-nx*nx);
	fx = sqrt(tr*tr-ny*ny);
	deg = atan2(fy,nx)-atan2(ny,fx);
	return deg*tr*tr/2 - (fy*fx-ny*nx)/2 + (fy-ny)*(fx-nx)/2;
}
void solve(int _loop) {
	int i,j,k,m,result;
	double ta,ha,re;
	
	PI=atan(1.0)*4;
	scanf("%lf %lf %lf %lf %lf",&f,&R,&t,&r,&g);
	tr = R-t-f;
	ta = R*R*PI/4;
	ha=0;
	if(g>2*f) {
		for(i=0;;i++) {
			double nx=r+f+(g+2*r)*i;
			if(nx>tr) break;
			for(j=0;;j++) {
				double ny = r+f+(g+2*r)*j;
				if(nx*nx+ny*ny>=tr*tr) break;
				re = segment(max(nx,ny),min(nx,ny));
				ha += re;
			}
		}
	}

	
	_PE("Case #%d: %.8lf\n",_loop, 1-ha/ta);
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



