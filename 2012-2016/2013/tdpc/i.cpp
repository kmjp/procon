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

int L;
string S;

int reducable[322][322];
int mama[322];

void solve() {
	int f,r,i,j,k,l, x,y,z;
	
	cin>>S;
	L=S.size();
	
	for(l=2;l<L;l+=3) {
		FOR(x,L) if(S[x]=='i') {
			z=x+l;
			if(z>=L || S[z]!='i') continue;
			for(y=x+1;y<z;y++) if(S[y]=='w') {
				if((reducable[x+1][y]||(x+1==y)) && (reducable[y+1][z]||(y+1==z))) 
					reducable[x][z+1] = (l+2)/3;
			}
			for(y=x+1;y<z;y++) if(reducable[x][y] && reducable[y][z+1])
				reducable[x][z+1] = (l+2)/3;
		}
	}
	for(x=L-1;x>=0;x--) {
		mama[x]=mama[x+1];
		for(y=x;y<=L;y++) mama[x]=max(mama[x], reducable[x][y]+mama[y]);
	}
	
	return _P("%d\n",mama[0]);
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


