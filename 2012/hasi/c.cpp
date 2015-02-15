/* ñ¢ê≥â */


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
#include <sys/time.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

typedef signed long long s64;
typedef unsigned long long u64;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N;
char A[500][500];
char S[500][500];
char K[500][500];
char L[500][500];

int same(int x,int y) {
	int s,l,sl,ll,sll,lll;
	if(strcmp(S[x],S[y])!=0) return 0;
	if(strlen(L[x])!=strlen(L[y])) return 0;
	
	if(strlen(L[x])==0) {
		if(strcmp(K[x],K[y])!=0) return 0;
		return 1;
	}
	
	if(strlen(K[x])<strlen(K[y])) {
		s=x;l=y;
	}
	else {
		s=y;l=x;
	}
	
	sl=strlen(K[s]);
	ll=strlen(K[l]);
	
	sll=strlen(L[s]);
	
	int i;
	FOR(i,ll) {
		if(i<sl) {
			if(K[s][i]!=K[l][i]) return 0;
		}
		else {
			if(L[s][(i-sl)%sll]!=K[l][i]) return 0;
		}
	}
	
	FOR(i,sll) {
		if(L[s][(i+(ll-sl))%sll]!=L[l][i]) return 0;
		
	}
	return 1;
}

void shorten(char* c) {
	int l = strlen(c);
	int i,j,k,ok;
	for(i=1;i<=l/2;i++) {
		if(l%i!=0) continue;
		ok=1;
		FOR(j,l) {
			if(c[j]!=c[j%i]) { ok=0; break;}
		}
		if(ok) {
			c[i]=0;
			return;
		}
		
	}
	
}

int addsplit(int id,char* c){
	char* pc,*pc2,pc3;;
	
	pc=strchr(c,'.');
	if(pc) {
		*pc=0;
		strcpy(S[id],c);
		pc++;
		pc2=strchr(pc,'(');
		if(pc2) {
			*pc2=0;
			strcpy(K[id],pc);
			pc=pc2+1;
			pc2=strchr(pc,')');
			*pc2=0;
			strcpy(L[id],pc);
			shorten(L[id]);
			
			pc=L[id];
			while(*pc) {
				if(*pc!='0') {
					pc=NULL;
					break;
				}
				pc++;
			}
			if(pc) {
				L[id][0]=0;
				goto out;
			}
			
			
			pc=L[id];
			// all 9?
			while(*pc) {
				if(*pc!='9') {
					pc=NULL;
					break;
				}
				pc++;
			}
			
			if(pc) {
				L[id][0]=0;
				//è¨êî
				pc=&K[id][strlen(K[id])-1];
				while(pc>=K[id]) {
					if(*pc=='9') {
						*pc='0';
						pc--;
					}
					else {
						*pc=*pc+1;
						break;
					}
				}
				if(pc<K[id]) {
					pc=&S[id][strlen(S[id])-1];
					while(pc>=S[id]) {
						if(*pc=='9') {
							*pc='0';
							pc--;
						}
						else {
							*pc=*pc+1;
							break;
						}
					}
					if(pc<S[id]) {
						memmove(S[id]+1,S[id],strlen(S[id])+1);
						S[id][0]='1';
					}
				}
				
			}
			
		}
		else {
			strcpy(K[id],pc);
			L[id][0]=0;
		}
		
	}
	else {
		strcpy(S[id],c);
		K[id][0]=L[id][0]=0;
	}
	out:
	//_P("%s.%s(%s)\n",S[id],K[id],L[id]);
	int i;
	FOR(i,id) {
		if(same(i,id)) return 0;
	}
	
	
	return 1;
}

void solve() {
	int i,c1,c2;
	int x,y,ok;
	
	ZERO(A);
	ZERO(S);
	ZERO(K);
	ZERO(L);
	
	N=GETi();
	FOR(i,N){
		GETs(A[i]);
		ok=addsplit(i,A[i]);
		if(!ok) {
			i--;N--;
		}
		
	}
	
	
	_P("%d\n",N);
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&ts,NULL);
	
	init();
	solve();
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



