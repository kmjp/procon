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


int T,W,Q,q[100],N,C;
char line[1000];
unsigned long long Com[50][50];
char lines[21][21];
int ga=0;

#define Gap 100
#define Range (250+Gap*2)
char path[Range][20*20][1000];
int steps;

void step() {
	int x,y,v,vv,l,i,j;
	int ox,oy,vx,vy;
	char tmp[1002];
	
	steps++;
	FOR(x,W) {
		FOR(y,W) {
			if((x+y)%2==1-ga) continue;
			
			FOR(l,16) {
				if(l%4==0) { ox=-1; oy=0; }
				if(l%4==1) { ox=1; oy=0; }
				if(l%4==2) { ox=0; oy=-1; }
				if(l%4==3) { ox=0; oy=1; }
				if((l/4)%4==0) { vx=-1; vy=0; }
				if((l/4)%4==1) { vx=1; vy=0; }
				if((l/4)%4==2) { vx=0; vy=-1; }
				if((l/4)%4==3) { vx=0; vy=1; }
				ox+=x; oy+=y;
				vx+=ox; vy+=oy;
				if(ox<0 || vx<0 || oy<0 || vy<0 || ox>=W || vx>=W || oy>=W || vy>=W) {
					continue;
				}
				
				v = (lines[vy][vx]-'0')*(lines[oy][ox]=='+' ? 1 : -1);
				FOR(vv,Range) {
					if(vv+v<0 || vv+v>=Range) continue;
					//if(vv+v==Gap+6) printf("%d %d %c %c\n",vv,v,lines[vy][vx],lines[oy][ox]);
					//if(vv+v==Gap+14) printf("aa<%d>[%d,%d]-[%d,%d]-[%d,%d] %d %d *%c /%c <%s>\n",steps,y,x,oy,ox,vy,vx,vv,v,lines[vy][vx],lines[oy][ox],path[vv][y*W+x]);
					if(strlen(path[vv][y*W+x])!=steps*2-1) continue;
					
					sprintf(tmp,"%s%c%c",path[vv][y*W+x],lines[oy][ox],lines[vy][vx]);
					/*
					if(lines[oy][ox]=='+' && path[vv][y*W+x][0]>lines[vy][vx]) {
						sprintf(tmp,"%c+%s",lines[vy][vx],path[vv][y*W+x]);
						//printf("okok %s\n",tmp);
					}
					else {
						int fp=0;
						strcpy(tmp,path[vv][y*W+x]);
						for(fp=1;fp<steps;fp++) {
							if(lines[oy][ox] < tmp[fp*2-1] ||
							   (lines[oy][ox] == tmp[fp*2-1] && lines[vy][vx] < tmp[fp*2]))
							   break;
						}
						
						if(fp==steps) {
							sprintf(tmp,"%s%c%c",path[vv][y*W+x],lines[oy][ox],lines[vy][vx]);
						}
						else {
							memmove(&tmp[fp*2+1],&path[vv][y*W+x][fp*2-1],(steps-fp)*2);
							tmp[fp*2-1]=lines[oy][ox];
							tmp[fp*2]=lines[vy][vx];
							tmp[steps*2+2]=0;
						}
					}
					*/
					
					if(strlen(path[vv+v][vy*W+vx]) == 0 || strlen(path[vv+v][vy*W+vx]) > strlen(tmp) || 
						((strlen(path[vv+v][vy*W+vx]) == strlen(tmp)) && strcmp(tmp,path[vv+v][vy*W+vx])<0)) {
//						if(vv+v==Gap+14) printf("[%d,%d]-[%d,%d] <%s> <%s> <%s>\n",y,x,vy,vx,path[vv][y*W+x],tmp,path[vv+v][vy*W+vx]);
						strcpy(path[vv+v][vy*W+vx],tmp);
					}
				}
			}
			
			
		}
	}
	
}


char* search(int q) {
	int x,y;
	char* r=NULL;
	
	FOR(x,W) {
		FOR(y,W) {
			if((x+y)%2==ga && path[q][y*W+x][0]!=0) {
				//printf("%d-%d %s\n",x,y,path[q][y*W+x]);
				if(r) {
					if(strlen(r)<strlen(path[q][y*W+x]))
						continue;
					if(strlen(r)==strlen(path[q][y*W+x]) && strcmp(r,path[q][y*W+x])<=0)
						continue;
				}
				r = path[q][y*W+x];
			}
		}
	}
	return r;
}


int main(int argc,char** argv){
	int loop,y,x,t,nx,ny,nt,tmp,i,j;
	int t1,t2,t3;
	char* r;
	float f;
	unsigned int result;
	double d;
	
	GET1(&T);
	
	
	for(loop=1;loop<=T;loop++) {
		GET2(&W,&Q);
		gets(line);
		FOR(i,W) {
			gets(lines[i]);
		}
		printf("Case #%d:\n",loop);
		fprintf(stderr,"Case #%d:\n",loop);
		FOR(i,Range) {
			FOR(x,W) {
				FOR(y,W) {
					path[i][y*W+x][0]=0;
				}
			}
		}
		
		ga = (lines[0][0]<'0' ? 1 : 0);
		FOR(x,W) {
			FOR(y,W) {
				if((x+y)%2==ga) {
					path[lines[y][x]-'0'+Gap][y*W+x][0]=lines[y][x];
					path[lines[y][x]-'0'+Gap][y*W+x][1]=0;
				}
			}
		}
		steps=0;
		
		FOR(i,Q) {
			GET1(&j);
			while(1){
				r=search(j+Gap);
				if(r || steps>5000) break;
				step();
			}
			printf("%s\n",r);
		}
		
		
	}
	return 0;
	
}



