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
#define GETS(x) {gets(x);remove_r(x);}
#define GETs(x) scanf("%s",x);
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);


void remove_r(char* p) {char* pp=strstr(p,"\r"); if(pp) *pp=0;}


int loops;
int T,N,M,L,A;
int d[10];
char line[1000];
char val[256];
char f[100][100];
char str[100*100], *strp;


int main(int argc,char** argv){
	int loop,i,j,okt,k,l,state,n,digit;
	unsigned long long result;
	char* pp;
	char fe[100][100];
	float pr;
	
	GET1(&loops);
	
	for(loop=1;loop<=loops;loop++) {
		GETs(line);
		result=0;
		
		FOR(i,256) val[i]=-1;
		digit=0;
		FOR(i,strlen(line)) {
			if(val[line[i]]==-1) {
				if(digit==0) val[line[i]]=1;
				else if(digit==1) val[line[i]]=0;
				else val[line[i]]=digit;
				digit++;
			}
		}
		if(digit==1) digit=2;
		FOR(i,strlen(line)) {
			result = result*digit + val[line[i]];
		}
		//if(strlen(line)==1) result=0;
		
		printf("Case #%d: %lld\n",loop,result);
		fprintf(stderr,"Case #%d: %lld\n",loop,result);
		

	}
	return 0;
	
}



