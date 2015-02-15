

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a,b,c) memset(a,0,c)


char lang[5000][15];
char match[15][256];
char line[5000];


int main(int argc,char** argv){
	int loop;
	int L,D,N,i,j,k;
	char buf[256];
	long result;
	int pos=0;
	
	scanf("%d %d %d",&L,&D,&N);
	gets((char*)lang[0]);
	
	FOR(i,D) {
		gets(lang[i]);
		lang[i][L]=0;
	}
	
	for(loop=1;loop<=N;loop++) {
		gets(line);
		//printf("%d %s\n",loop,line);
		memset(match,0,sizeof(match));
		
		pos=1;
		FOR(i,5000) {
			if(line[i]==0) break;
			
			if(line[i]=='('){
				pos=-pos;
			}
			else if(line[i]==')'){
				pos=(-pos)+1;
			}
			else {
				int tpos = pos;
				if(pos<0) tpos=-tpos;
				match[tpos-1][line[i]]=1;
				if(pos>0) pos++;
			}
		}
		result=0;
		for(i=0;i<D;i++){
			for(j=0;j<L;j++) {if(match[j][lang[i][j]]==0) break;}
			if(j==L) result++;
		}
		
		printf("Case #%d: %d\n",loop,result);
	}
	
	return 0;
	
}



