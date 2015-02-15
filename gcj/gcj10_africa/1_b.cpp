
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define ZERO2(a,b) memset(a,0,b)
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

char d[1000][1000];
char line[5000];

int N,C,L,T,E;
int home[5000],car[5000];
int PT[100],PC[100],PCL[100][500],ok[100];

int main(int argc,char** argv){
	int loop,i,j,okt,k,l;
	char* p;
	
	GET1(&C);
	for(loop=1;loop<=C;loop++) {
		GET2(&N,&T);
		GET1(&E);
		
		ZERO(PT);
		ZERO(PC);
		ZERO(PCL);
		ZERO(ok);
		
		FOR(i,E){
			GET2(&home[i],&car[i]);
			home[i]--;
			PT[home[i]]++;
			if(car[i]>0) {
				PCL[home[i]][PC[home[i]]]=car[i];
				PC[home[i]]++;
			}
		}
		
		okt=0;
		FOR(i,N){
			if(PT[i]==0 || i==T-1){
				ok[i]=0;
				continue;
			}
			//sort
			for(j=0;j<PC[i]-1;j++){
				for(k=j+1;k<PC[i];k++){
					if(PCL[i][j]<PCL[i][k]) {
						int tmp =PCL[i][k];
						PCL[i][k]=PCL[i][j];
						PCL[i][j]=tmp;
					}
				}
			}
			for(ok[i]=1;ok[i]<=PC[i];ok[i]++){
				PT[i]-=PCL[i][ok[i]-1];
				if(PT[i]<=0) break;
			}
			if(PT[i]>0) {
				okt=1;
				break;
			}
			
		}
		if(okt) {
			printf("Case #%d: IMPOSSIBLE\n",loop);
		}
		else {
			printf("Case #%d: ",loop);
			FOR(i,N){
				printf("%d",ok[i]);
				if(i<N-1) printf(" ");
			}
			printf("\n");
		}
		
	}
	return 0;
	
}



