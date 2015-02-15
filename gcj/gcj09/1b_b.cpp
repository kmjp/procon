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
int d[10];
char line[1000],line2[1000];;


int main(int argc,char** argv){
	unsigned int loop,y,x,t,nx,ny,nt,tmp,i,j,k,l;
	unsigned int t1,t2,t3;
	
	unsigned int result;
	
	GET1(&T);
	
	for(loop=1;loop<=T;loop++) {
		scanf("%s",line);
		strcpy(line2,line);
		l=strlen(line);
		
		j=0;
		for(i=l;i>0;i--) {
			if(line[i-1]<line[i]) break;
		}
		
		if(i==0) {
			
			for(i=1;i<=l;i++) {
				line[i]=line2[l-i];
			}
			line[l+1]=0;
			for(i=1;i<=l;i++) {
				if(line[i]!='0') {
					line[0]=line[i];
					line[i]='0';
					break;
				}
			}
		}
		else {
			i--;
repeat:
			int minst='a',minid=-1;
			for(j=i+1;j<l;j++){
				if(line[j]>line[i] && line[j]<minst) {
					minst=line[j]; minid=j;
				}
			}
			if(minid==-1){
				i++;
				goto repeat;
			}
			line[minid]=line[i];
			line[i]=minst;
			for(j=i+1;j<l-1;j++) {
				for(k=j+1;k<l;k++) {
					if(line[j]>line[k]) {
						tmp=line[j];
						line[j]=line[k];
						line[k]=tmp;
					}
				}
			}
			
		}
		
		printf("Case #%d: %s\n",loop,line);
		fprintf(stderr,"Case #%d: %s\n",loop,line);
	}
	return 0;
	
}



