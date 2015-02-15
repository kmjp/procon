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

int N,M,K;
int T[100001];
int S[100001];
map<pair<int,int>, int> FT;

void solve() {
	int x,y,i,j,c,w,t;
	char st[10];
	
	GET3(&N,&M,&K);
	ZERO(T);
	ZERO(S);
	FT.clear();
	FOR(i,M) {
		GETs(st);
		w=GETi()-1;
		if(st[0]=='t') {
			T[w]++;
		}
		else if(st[0]=='f') {
			t=GETi()-1;
			FT.insert(make_pair(make_pair(w,t),T[t]));
			FT.insert(make_pair(make_pair(t,w),T[w]));
		}
		else {
			t=GETi()-1;
			S[w]+=T[t]-FT[make_pair(w,t)];
			S[t]+=T[w]-FT[make_pair(t,w)];
			FT.erase(make_pair(w,t));
			FT.erase(make_pair(t,w));
		}
	}
	
	map<pair<int,int>, int>::iterator it;
	for(it=FT.begin();it!=FT.end();it++) {
		pair<int,int> p=(*it).first;
		S[p.first] += T[p.second] - (*it).second;
	}
	FOR(i,N) T[i]+=S[i];
	
	sort(T,T+N);
	_P("%d\n",T[(N-1)-(K-1)]);
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

