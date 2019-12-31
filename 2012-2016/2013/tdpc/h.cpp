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

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
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

int N,TW,TC;
int W[10001],V[10001],C[10001];
int dpdp[52][10002];
int tmp[10002];
vector<int> WW[52];

void solve() {
	int f,r,i,j,k,l, x,y,z;
	
	cin>>N>>TW>>TC;
	FOR(i,N) {
		cin>>W[i]>>V[i]>>x;
		WW[x-1].push_back(i);
	}
	
	int ma=0,col,w;
	FOR(i,50) {
		for(col=TC;col>=0;col--) {
			memmove(tmp,dpdp[col],sizeof(tmp));
				
			FOR(j,WW[i].size()) {
				int tar=WW[i][j];
				for(w=TW;w>=W[tar];w--) tmp[w]=max(tmp[w],tmp[w-W[tar]]+V[tar]);
			}
			
			for(w=TW;w>=0;w--)
				dpdp[col+1][w] = max(dpdp[col+1][w], tmp[w]);
		}
	}
	
	FOR(i,TC+1) FOR(w,TW+1) ma=max(ma,dpdp[i][w]);
	
	return _P("%d\n",ma);
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


