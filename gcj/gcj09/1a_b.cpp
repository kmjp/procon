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


int N,M,C;
int d[10];
char line[1000];
unsigned int  data[10][1000];
unsigned int S[200][200],W[200][200],T[200][200];
unsigned int Time[300][300];
int Proc[300][300];


int main(int argc,char** argv){
	unsigned int loop,y,x,t,nx,ny,nt,tmp,i,j;
	unsigned int t1,t2,t3;
	
	unsigned int result;
	
	GET1(&C);
	
	for(loop=1;loop<=C;loop++) {
		GET2(&N,&M);
		FOR(i,N) {
			FOR(j,M) {
				GET3(&S[i][j],&W[i][j],&T[i][j]);
				T[i][j] = T[i][j] % (S[i][j]+W[i][j]);
			}
		}
		FOR(i,(2*N)) {
			FOR(j,(2*M)) {
				Time[i][j]=~0UL;
				Proc[i][j]=0;
			}
		}
		x = t = 0;
		y = (2*N-1);
		Time[y][x]=0;
		Proc[y][x]=1;
		
		while(1) {
			if(x==(2*M-1) && y==0) break;
			nx=ny=nt=~0UL;
			
			if(y>0 && Proc[y-1][x]==0) {
				if(y%2) {
					if(S[y/2][x/2]>0) {
						t1=t-T[y/2][x/2] + S[y/2][x/2]+W[y/2][x/2];
						t2=t1%(S[y/2][x/2]+W[y/2][x/2]);
						if(t2>S[y/2][x/2]-1) {
							tmp = t + (S[y/2][x/2]+W[y/2][x/2]-t2)+1;
						}
						else
							tmp = t+1;
					}
					else tmp=~0UL;
				}
				else tmp = t+2;
				
				if(Time[y-1][x]==~0UL || Time[y-1][x]>tmp)
					Time[y-1][x]=tmp;
				//printf("**%d %d %d %d %d\n",x,y,x,y-1,tmp);
			}
			if(y<2*N-1 && Proc[y+1][x]==0) {
				if((y%2)==0 ) {
					if(S[y/2][x/2]>0) {
						t1=t-T[y/2][x/2] + S[y/2][x/2]+W[y/2][x/2];
						t2=t1%(S[y/2][x/2]+W[y/2][x/2]);

						if(t2>S[y/2][x/2]-1)
							tmp = t + (S[y/2][x/2]+W[y/2][x/2]-t2)+1;
						else
							tmp = t+1;
					}
					else tmp=~0UL;
				}
				else tmp = t+2;
				
				if(Time[y+1][x]==~0UL || Time[y+1][x]>tmp)
					Time[y+1][x]=tmp;
				//printf("**%d %d %d %d %d\n",x,y,x,y+1,tmp);
			}
			if(x>0 && Proc[y][x-1]==0) {
				if((x%2)) {
					if(W[y/2][x/2]>0) {
						t1=t-T[y/2][x/2]+S[y/2][x/2]+W[y/2][x/2];
						t2=t1%(S[y/2][x/2]+W[y/2][x/2]);
						
						if(t2<=S[y/2][x/2])
							tmp = t + (S[y/2][x/2]-t2)+1;
						else
							tmp = t+1;
					}
					else tmp=~0UL;
				}
				else tmp = t+2;
				
				if(Time[y][x-1]==~0UL || Time[y][x-1]>tmp)
					Time[y][x-1]=tmp;
				//printf("**%d %d %d %d %d\n",x,y,x-1,y,tmp);
			}
			if(x<2*M-1 && Proc[y][x+1]==0) {
				if((x%2)==0) {
					if(W[y/2][x/2]>0) {
						t1=t-T[y/2][x/2] + S[y/2][x/2]+W[y/2][x/2];
						t2=t1%(S[y/2][x/2]+W[y/2][x/2]);
						if(t2<=S[y/2][x/2])
							tmp = t + (S[y/2][x/2]-t2)+1;
						else
							tmp = t+1;
					}
					else tmp=~0UL;
				}
				else tmp = t+2;
				
				if(Time[y][x+1]==~0UL || Time[y][x+1]>tmp)
					Time[y][x+1]=tmp;
				//printf("**%d %d %d %d %d\n",x,y,x+1,y,tmp);
			}
			nx=ny=nt=~0UL;
			//fprintf(stderr,"+%d %d %d %d %d %d \n",nt,nx,ny,t,x,y);
			FOR(i,(2*N)) {
				FOR(j,(2*M)) {
					if(Time[i][j]!=~0UL && Time[i][j]<nt && Proc[i][j]==0) {
						nt = Time[i][j];
						nx = j;
						ny=i;
					}
				}
			}
			//fprintf(stderr,"%d %d %d %d %d %d \n",nt,nx,ny,t,x,y);
			t=nt;
			x=nx;
			y=ny;
			Proc[y][x]=1;
		}
		
		result = Time[0][2*M-1];
		
		printf("Case #%d: %u\n",loop,result);
		fprintf(stderr,"Case #%d: %u\n",loop,result);
	}
	return 0;
	
}



