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

int H,W;
ll pat=0;

int mat[101][101];

void dfs(int y,int x) {
	
	if(x>=W) x=0,y++;
	if(y>=H) {
		pat++;
		/*
		FOR(y,H) {
			FOR(x,W) _P("%d",mat[y][x]);
			_P("\n");
		}
		_P("------\n");
		*/
		return;
	}
	
	int t=mat[y][x];
	//1
	if((y==0||mat[y-1][x]!=1)&&(x==0||mat[y][x-1]!=1)) {
		if(t==0 || t==1) {
			mat[y][x]=1;
			dfs(y,x+1);
			mat[y][x]=t;
		}
	}
	if((y<1||mat[y-1][x]!=2)&&(y<2||mat[y-2][x]!=2)&&
	   (x<1||mat[y][x-1]!=2)&&(x<2||mat[y][x-2]!=2)) {
		if(t==0 || t==2) {
			mat[y][x]=2;
			dfs(y,x+1);
			mat[y][x]=t;
		}
	}
	if((y<1||mat[y-1][x]!=3)&&(y<2||mat[y-2][x]!=3)&&(y<3||mat[y-3][x]!=3)&&
	   (x<1||mat[y][x-1]!=3)&&(x<2||mat[y][x-2]!=3)&&(x<3||mat[y][x-3]!=3)) {
		if(t==0 || t==3) {
			mat[y][x]=3;
			dfs(y,x+1);
			mat[y][x]=t;
		}
	}
	
	
}


void solve() {
	int f,r,i,j,k,l,x,y,tx,ty,aa[5];
	
	cin>>H>>W;
	if(H>12) H=12+H%4;
	if(W>12) W=12+W%4;
	dfs(0,0);
	_P("%lld\n",pat);
	
	return;
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
