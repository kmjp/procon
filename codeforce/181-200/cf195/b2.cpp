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


ll M,R;
void solve() {
	ll i,f,r,j,k,l,x,y,tx,ty,aa[5];
	cin>>M>>R;
	// same
	double T=2*M;
	
	FOR(i,M) {
		l=i;
		r=M-1-i;
		
		//��
		if(l>0) T+=2+sqrt(2);
		if(r>0) T+=2+sqrt(2);
		//2�ȏ�
		if(l>=2) T+=(l)*(l-1) + (l-1)*2*sqrt(2);
		if(r>=2) T+=(r)*(r-1) + (r-1)*2*sqrt(2);
		
	}
	
	_P("%.12lf\n",R*T/(M*M));
	
	return;
}


int main(int argc,char** argv){
	
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
