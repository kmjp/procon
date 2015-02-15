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

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define ZERO2(a,b) memset(a,0,b)
#define GETs(x) scanf("%s",x);
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);


int N,M,C,T;
char line[1000],line2[1000];;
double tx,ty,tz,tvx,tvy,tvz,a2,a1,a0,d,t,t1,t2;

int main(int argc,char** argv){
	unsigned int loop,nt,tmp,i,j,k,l;
	int x,y,z,vx,vy,vz;
	
	unsigned int result;
	
	GET1(&T);
	
	for(loop=1;loop<=T;loop++) {
		GET1(&N);
		tx=ty=tz=tvx=tvy=tvz=0;
		FOR(i,N) {
			scanf("%d%d%d%d%d%d",&x,&y,&z,&vx,&vy,&vz);
			tx+=x;
			ty+=y;
			tz+=z;
			tvx+=vx;
			tvy+=vy;
			tvz+=vz;
		}
		a2 = tvx*tvx+tvy*tvy+tvz*tvz;
		a1 = 2*(tx*tvx + ty*tvy + tz*tvz);
		a0 = tx*tx+ty*ty+tz*tz;
		//printf("a1a2a3 %f %f %f %f\n",(float)a2,(float)a1,(float)a0);
		if(a2>1e-9) {
			
			d = a1*a1-4*a0*a2;
			//printf("%f %f %f %f\n",(float)a2,(float)a1,(float)a0,(float)d);
			if(d<=1e-9) {
				t = -a1 / (2*a2);
				if(t<=1e-9){
					d = sqrt(a0)/N; t=0.0;
				}
				else {
					d = sqrt(abs(t*t*a2 + t*a1+a0))/N;
				}
			}
			else {
				d = sqrt(d);
				t1 = (-a1 - d) / (2*a2);
				t2 = (-a1 + d) / (2*a2);
				if(t1>0.0) {
					t=t1;
					d = sqrt(abs(t*t*a2 + t*a1+a0))/N;
				}
				else {
					d = sqrt(a0)/N; t=0.0;
				}
			}
			//printf("%f %f %f %f %f\n",(float)a2,(float)a1,(float)a0,(float)t1,t*t*a2 + t*a1+a0);
		}
		else if(a1>=-1e-9 && a1<=1e-9) {
			d = sqrt(a0)/N; t=0.0;
		}
		else {
			if(a1>0.0) {
				d = sqrt(a0)/N; t=0.0;
			}
			else {
				t = a0/a1;
				d = 0.0;
			}
		}
		printf("Case #%d: %0.8f %0.8f\n",loop,d,t);
		fprintf(stderr,"Case #%d: %0.8f %0.8f\n",loop,d,t);
	}
	return 0;
	
}



