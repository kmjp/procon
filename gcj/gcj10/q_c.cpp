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


int T,R,k,N,tk;
char line[1000];
unsigned long long Com[50][50];
double E[50];
int g[1000];
int t[1000];
int np[1000];



int main(int argc,char** argv){
	unsigned int loop,y,x,nx,ny,nt,tmp,i,j;
	unsigned int t1,t2,t3;
	float f;
	unsigned long long result;
	double d;
	int pos;
	
	GET1(&T);
	for(loop=1;loop<=T;loop++) {
		GET3(&R,&k,&N);
		ZERO(t);
		ZERO(np);
		FOR(i,N) GET1(&g[i]);
		FOR(i,N) {
			t[i]=0;
			for(j=0;j<N;j++) {
				if(t[i]+g[(i+j)%N]>k) break;
				t[i]+=g[(i+j)%N];
			}
			np[i]=(i+j)%N;
		}
		
		
		result=0;pos=0;
		FOR(i,R) {
			result += t[pos];
			pos=np[pos];
		}
		
		printf("Case #%d: %lld\n",loop,result);
		fprintf(stderr,"Case #%d: %lld\n",loop,result);
	}
	return 0;
	
}



