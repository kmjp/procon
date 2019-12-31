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

int K,N;
int NG[100001];
set<s64> rank[51];
vector<s64> vec;

void solve() {
	int f,t,g;
	int m,i,j;
	s64 d,s;
	int sum,max;
	int vx,vy;
	char ll[30];
	
	s64 P,Q,T;
	K=GETi();
	N=GETi();
	FOR(i,N){ scanf("%lld %lld",&P,&Q);Q--; vec.push_back((P<<52)+Q); }
	FOR(i,51) rank[i].clear();
	sort(vec.begin(),vec.end());
	
	
	//NG
	ZERO(NG);
	int ok;
	FOR(i,N) {
		ok=1;
		T=vec[i];
		P=T>>52;
		Q=T-(P<<52);
		FOR(j,P) {
			set<s64>::iterator iti = rank[j].find(Q>>(P-j));
			if(iti!=rank[j].end()) {
				ok=0;
				NG[i]=1;
				break;
			}
		}
		if(ok && P<K) {
			rank[P].insert(Q);
		}
	}
	
	s = (1LL<<(K+1))-1;
	FOR(i,N) {
		if(NG[i]==0){
			T=vec[i];
			P=T>>52;
			Q=T-(P<<52);
			s-= (1LL<<(K-P+1))-1;
		}
	}
	_P("%lld\n",s);
	
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



