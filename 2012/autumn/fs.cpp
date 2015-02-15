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

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) { printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__); }
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
ll GETi() { ll i;scanf("%lld",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N;
int flag;
double A[10001];
int len[10001];
int mal[51][51],mil[51][51];
double ma[51][51],mi[51][51];


void dfs(int s,int t,int flag,int dep) {
	if(s+1==t) {
		return;
	}
	if(s+2==t) {
		len[s+1]=dep;
		return;
	}
	
	if(flag) {
		len[mil[s][t]]=dep;
		dfs(s,mil[s][t],1,dep+1);
		dfs(mil[s][t],t,0,dep+1);
	}
	else {
		len[mal[s][t]]=dep;
		dfs(s,mal[s][t],0,dep+1);
		dfs(mal[s][t],t,1,dep+1);
	}
}

double calc(int s,int t,int flag, int dep) {
	int tar,best;
	double da,r;
	if(s+1==t) { return A[s];}
	if(s+2==t) { 
		mal[s][t]=mil[s][t]=s+1;
		return A[s]/A[s+1];
	}
		
	
	
	da=0;
	if(flag) {
		//min
		if(mil[s][t]==0) {
			best=-1;
			for(tar=s+1;tar<t;tar++) {
				r = calc(s,tar, 1, dep+1) / calc(tar,t, 0, dep+1);
				if(best==-1 || r<da) {
					da=r;
					best=tar;
				}
			}
			mil[s][t]=best;
			mi[s][t]=da;
		}
		return mi[s][t];
	}
	else {
		if(mal[s][t]==0) {
			best=-1;
			for(tar=s+1;tar<t;tar++) {
				r = calc(s,tar, 0, dep+1) / calc(tar,t, 1, dep+1);
				if(best==-1 || r>da) {
					da=r;
					best=tar;
				}
			}
			mal[s][t]=best;
			ma[s][t]=da;
		}
		return ma[s][t];
	}
}

void solve() {
	int x,y,i,j,p,rr,TM,TTC;
	
	flag=0;
	N=GETi();
	FOR(i,N) {
		scanf("%lf",&A[i]);
		if(A[i]<0){ flag = 1-flag; A[i]=-A[i];};
	}
	
	ZERO(mal);
	ZERO(mil);
	if(N>=51) return;
	calc(0,N,flag,1);
	ZERO(len);
	dfs(0,N,flag,1);
	
	vector<pair<int,int> > num;
	FOR(i,N-1) {
		num.push_back(make_pair(10000-len[i+1],i));
	}
	sort(num.begin(),num.end());
	int resa[10001];
	FOR(i,N-1) {
		resa[num[i].second]=i+1;
	}
	FOR(i,N-1) {
		_P("%d\n",resa[i]);
	}
	
	
	return;
}

int main(int argc,char** argv){
	long long span;
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&start,NULL);
	solve();
	gettimeofday(&end,NULL);
	
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}

