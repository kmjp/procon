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
#include <unistd.h>

typedef signed long long ll;
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

int H,W,N;
string S[16];
int B[16],C[16],BT[1000];;


void solve() {
	int f,r,i,j,k,l,x,y,tx,ty,aa[5];
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	cin>>N;
	FOR(i,N) {
		cin>>x;
		BT[i]=x;
		B[x-1]++;
	}
	
	int npat=(H/4)*(W/4);
	FOR(i,1<<npat) {
		FOR(j,16) C[j]=B[j];
		FOR(y,H/4) FOR(x,W/4) {
			int id=y*(W/4)+x;
			int sl=(i&(1<<id));
			if(!sl) {
				aa[id*4+0]=(S[y*4+0][x*4+0]=='#')+(S[y*4+1][x*4+0]=='#')*2+(S[y*4+1][x*4+1]=='#')*4+(S[y*4+2][x*4+0]=='#')*8;
				aa[id*4+2]=(S[y*4+3][x*4+3]=='#')+(S[y*4+2][x*4+3]=='#')*2+(S[y*4+2][x*4+2]=='#')*4+(S[y*4+1][x*4+3]=='#')*8;
				aa[id*4+1]=(S[y*4+0][x*4+3]=='#')+(S[y*4+0][x*4+2]=='#')*2+(S[y*4+1][x*4+2]=='#')*4+(S[y*4+0][x*4+1]=='#')*8;
				aa[id*4+3]=(S[y*4+3][x*4+0]=='#')+(S[y*4+3][x*4+1]=='#')*2+(S[y*4+2][x*4+1]=='#')*4+(S[y*4+3][x*4+2]=='#')*8;
			}
			else {
				aa[id*4+0]=(S[y*4+1][x*4+0]=='#')+(S[y*4+2][x*4+0]=='#')*2+(S[y*4+2][x*4+1]=='#')*4+(S[y*4+1][x*4+0]=='#')*8;
				aa[id*4+2]=(S[y*4+2][x*4+3]=='#')+(S[y*4+1][x*4+3]=='#')*2+(S[y*4+1][x*4+2]=='#')*4+(S[y*4+0][x*4+3]=='#')*8;
				aa[id*4+1]=(S[y*4+0][x*4+2]=='#')+(S[y*4+0][x*4+1]=='#')*2+(S[y*4+1][x*4+1]=='#')*4+(S[y*4+0][x*4+0]=='#')*8;
				aa[id*4+3]=(S[y*4+3][x*4+1]=='#')+(S[y*4+3][x*4+2]=='#')*2+(S[y*4+2][x*4+2]=='#')*4+(S[y*4+3][x*4+3]=='#')*8;
			}
			if(--C[aa[id*4+0]]<0) goto last;
			if(--C[aa[id*4+1]]<0) goto last;
			if(--C[aa[id*4+2]]<0) goto last;
			if(--C[aa[id*4+3]]<0) goto last;
		}
		
		FOR(j,N) {
			FOR(x,npat*4) {
				if(aa[x]+1==BT[j]) {
					int id=x/4;
					int dx[2][4]={{1,4,4,1},{1,3,4,2}};
					int dy[2][4]={{1,1,4,4},{2,1,3,4}};
					_P("%d %d %d\n",id%(W/4)*4+dx[(i&(1<<id))!=0][x%4],id/(W/4)*4+dy[(i&(1<<id))!=0][x%4],x%4);
					aa[x]=-1;
					break;
				}
			}
		}
		return;
		last:
		;
	}
	
	_P("-1\n");
	
	return;
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
