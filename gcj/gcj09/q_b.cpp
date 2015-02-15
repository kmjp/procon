
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a,b) memset(a,0,b)
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

int map[100][100];
int flow[100][100];
char line[5000];

int H,W;
int sink;

void color(int w,int h,int csink){
	if(flow[w][h]==csink) return;
	flow[w][h]=csink;
	if(w>0 && flow[w-1][h]==3) color(w-1,h,csink);
	if(h>0 && flow[w][h-1]==4) color(w,h-1,csink);
	if(w<W-1 && flow[w+1][h]==2) color(w+1,h,csink);
	if(h<H-1 && flow[w][h+1]==1) color(w,h+1,csink);
	
	
}

int follow_color(int w,int h,int csink) {
	int cw,ch,i;
	cw=w;ch=h;
	while(flow[cw][ch]>0){
		if(flow[cw][ch]==1) ch--;
		else if(flow[cw][ch]==2) cw--;
		else if(flow[cw][ch]==3) cw++;
		else if(flow[cw][ch]==4) ch++;
		else exit(0);
	}
	//printf("--%d %d %c\n",cw,ch,sink);
	color(cw,ch,csink);
}

int main(int argc,char** argv){
	int loop;
	int L,D,N,i,j,k;
	char buf[256];
	long result;
	int pos=0;
	int h,w;
	
	GET1(&L);
	
	for(loop=1;loop<=L;loop++) {
		GET2(&H,&W);
		FOR(h,H){
			FOR(w,W){
				GET1(&map[w][h]);
			}
		}
		
		ZERO(flow,sizeof(flow));
		FOR(h,H){
			FOR(w,W){
				int minst=999999;
				if(h>0 && map[w][h-1]<minst) minst=map[w][h-1];
				if(w>0 && map[w-1][h]<minst) minst=map[w-1][h];
				if(w<W-1 && map[w+1][h]<minst) minst=map[w+1][h];
				if(h<H-1 && map[w][h+1]<minst) minst=map[w][h+1];
				if(minst>=map[w][h]) {
					flow[w][h]=0;
					continue;
				}
				
				if(h>0 && map[w][h-1]==minst){ flow[w][h]=1; continue;}
				if(w>0 && map[w-1][h]==minst){ flow[w][h]=2; continue;}
				if(w<W-1 && map[w+1][h]==minst){ flow[w][h]=3; continue;}
				if(h<H-1 && map[w][h+1]==minst){ flow[w][h]=4; continue;}
				//printf("rr %d %d %d",w,h,minst);
			}
		}
		sink='a';
		FOR(h,H){
			FOR(w,W){
				if(flow[w][h]>='a') continue;
				follow_color(w,h,sink);
				sink++;
			}
		}
		
		
		printf("Case #%d:\n",loop);
		FOR(h,H){
			FOR(w,W){
				printf("%c",flow[w][h]);
				if(w!=W-1) printf(" ");
			}
			printf("\n");
		}
		
	}
	
	return 0;
	
}



