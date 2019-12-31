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

int W,H,A,B;
int tate[8][8];
int yoko[8][8];
int ma=0;

int check() {
	int num=0;
	int x,y,a=0,b=0;
	
	for(y=1;y<H-1;y++) {
		for(x=1;x<W-1;x++) {
			if(tate[y-1][x]==0 && tate[y][x]==1 && yoko[y][x-1]==0 && yoko[y][x]==1) b++; //deko
			if(tate[y-1][x]==1 && tate[y][x]==0 && yoko[y][x-1]==1 && yoko[y][x]==0) a++; //boko
		}
	}
	
	if(a<A || b>B) return 0;
	
	for(x=1;x<W-1;x++) {
		if(yoko[0][x-1]==1 && yoko[0][x]==0 && tate[0][x]==0) num++;
		if(yoko[H-1][x-1]==1 && yoko[H-1][x]==0 && tate[H-2][x]==1) num++;
	}
	for(y=1;y<H-1;y++) {
		if(tate[y-1][0]==1 && tate[y][0]==0 && yoko[y][0]==0) num++;
		if(tate[y-1][W-1]==1 && tate[y][W-1]==0 && yoko[y][W-2]==1) num++;
	}
	
	return num;
}

void dfs(int y,int x) {
	if(x>=W) x=0,y++;
	
	// null ok?
	if(y<H-1 && x<W-1) {
		tate[y][x]=0;yoko[y][x]=0;
		dfs(y,x+1);
		tate[y][x]=0;yoko[y][x]=1;
		dfs(y,x+1);
		tate[y][x]=1;yoko[y][x]=0;
		dfs(y,x+1);
		tate[y][x]=1;yoko[y][x]=1;
		dfs(y,x+1);
	}
	else if(y==H-1 && x<W-1) {
		yoko[y][x]=0;
		dfs(y,x+1);
		yoko[y][x]=1;
		dfs(y,x+1);
	}
	else if(y<H-1 && x==W-1) {
		tate[y][x]=0;
		dfs(y,x+1);
		tate[y][x]=1;
		dfs(y,x+1);
	}
	else {
		ma=max(ma,check());
	}
	
}

void solve() {
	int f,r,i,j,k,l,x,y,tx,ty,aa[5];
	ma=0;
	cin>>W>>H>>A>>B;
	if(W<H) swap(W,H);
	
	if(A==0 && B==(W-2)*(H-2)) {
		//small1
		if(B>=2) return (void)_P("%d\n",(W-2+1)/2*2+(H-2+1)/2*2);
		if(B==1) return (void)_P("4\n"); //3x3
		if(B==0) return (void)_P("%d\n",W-2); //
	}
	else if(H<=4) {
		ZERO(tate);
		ZERO(yoko);
		dfs(0,0);
		_P("%d\n",ma);
	}
	
	return;
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	
	return 0;
}
