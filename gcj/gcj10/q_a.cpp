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


int T,N,K;
int d[10];
char line[1000];
char data[41][41];
int state[31];


int main(int argc,char** argv){
	int loop,i,j,ok,k,l,state;
	unsigned long long result;
	char tmp[100];
	
	GET1(&T);
	for(loop=1;loop<=T;loop++) {
		GET2(&N,&K);
		//ZERO(state);
		
		
		printf("Case #%d: %s\n",loop,(((K & ((1<<N)-1))==(1<<N)-1)) ? "ON" : "OFF");
	}
	return 0;
	
}



