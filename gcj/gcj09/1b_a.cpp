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
int data[10][1000];
float p[100],  tl[100], fl[100];
char f[100][100];
char str[100*100], *strp;

int parse(int l) {
	int nl=l,n;
	char tline[100],t[100];
	char bl[100];
	
	if(sscanf(strp,"%[ (]%f%s%n",bl,&p[l],f[l],&n) ==3) {
		if(f[l][0]==')') {
			strp+=n-(strlen(f[l])-1);
			f[l][0]=0;
			l++;
		}
		else {
			l++;
			strp+=n;
			tl[nl] = l;
			l = parse(l);
			fl[nl] = l;
			l = parse(l);
			
			if(sscanf(strp,"%s%n",t,&n) != 1) {
				fprintf(stderr,"error bla %s\n",strp);
			}

			strp+=n-(strlen(t)-1);
		}
		return l;
	}
	else {
		fprintf(stderr,"[%d] error %d : %s\n",l,sscanf(strp,"%[ (]%f%s%n",bl,&p[l],f[l],&n),strp);
	}
	
	
}


int main(int argc,char** argv){
	int loop,i,j,okt,k,l,state,n;
	unsigned long long result;
	char* pp;
	GET1(&loops);
	char fe[100][100];
	float pr;
	
	for(loop=1;loop<=loops;loop++) {
		GET1(&L);
		GETS(line);
		str[0]=0;
		FOR(i,L) {
			GETS(line);
			strcat(str," ");
			strcat(str,line);
		}
		strp=str;
		parse(0);
		
		printf("Case #%d: \n",loop);
		fprintf(stderr,"Case #%d: \n",loop);
		GET1(&A);
		FOR(i,A) {
			GETs(line);
			GET1(&n);
			FOR(j,n){ GETs(fe[j]);  }
			pr = 1.0;
			l = 0;
			while(1) {
				int tr;
				pr *= p[l];
				if(f[l][0]==0) break;
				tr=0;
				FOR(j,n){
					if(strcmp(fe[j],f[l])==0) tr=1;
				}
				l = (tr? tl[l] : fl[l]);
			}
			printf("%0.7f\n",pr);
			
		}
		

	}
	return 0;
	
}



