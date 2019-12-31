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

int N,M,Q;
int MU[3];
int AD[3];
int PA,PB,PD;
int PI[3005][3005];
int MI[3005][3005];
ll IMO[3005][3005];
ll X[3005][3005];

void solve() {
	int x,y,i,j,p,rr,TM,TTC,dep,res;
	ll ret;
	
	GET3(&N,&M,&Q);
	GET3(&PA,&MU[0],&AD[0]);
	GET3(&PB,&MU[1],&AD[1]);
	GET3(&PD,&MU[2],&AD[2]);
	
	FOR(i,Q) {
		//â¡éZï™
		PI[999+PA-PD+1][999+PB]++;
		PI[999+PA+PD+1][999+PB]--;
		PI[999+PA+1][999+PB+PD]++;
		PI[999+PA+1][999+PB-PD]--;
		//å∏éZï™
		MI[999+PA-PD+1][999+PB+1]--;
		MI[999+PA+PD+1][999+PB+1]++;
		MI[999+PA+1][999+PB+PD+1]++;
		MI[999+PA+1][999+PB-PD+1]--;
		PA=(PA*MU[0]+AD[0])%N+1;
		PB=(PB*MU[1]+AD[1])%M+1;
		PD=(PD*MU[2]+AD[2])%max(N,M)+1;
	}
	ZERO(X);
	
	//ç∂â∫Ç…â¡éZ
	FOR(i,6000) {
		y=(i<=3000)?i:3000;
		x=(i<=3000)?0:(i-3000);
		p=0;
		while(y>=0 && x<=3000) {
			p+=PI[x][y];
			IMO[x][y]+=p;
			x++;y--;
		}
	}
	//âEâ∫Ç…â¡éZ
	FOR(i,6000) {
		y=(i<=3000)?i:0;
		x=(i<=3000)?0:(i-3000);
		p=0;
		while(y<=3000 && x<=3000) {
			p+=MI[x][y];
			IMO[x][y]+=p;
			x++;y++;
		}
	}
	
	ll PP=1000000007;
	ll MO=1000000009;
	FOR(x,3000) {
		p=0;
		if(x==0) FOR(y,3000) X[x][y]=(p=(p+IMO[x][y])%MO);
		else FOR(y,3000) X[x][y]=(X[x-1][y]+(p=(p+IMO[x][y])%MO))%MO;
	}
	
	ll hash=0;
	FOR(x,N) FOR(y,M) hash = (hash*PP+X[1000+x][1000+y])%MO;
	
	_P("%lld\n",hash);
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

