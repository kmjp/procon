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

int H,T;
int RT[101];
ll MO=1000003;
ll mod=MO;
ll dp[101][101][101];
ll dp2[101][101];

ll combi(ll N_, ll C_) {
	int i;
	const int num=100;
	static ll rev[num+1],revt[num+1];
	
	if(rev[1]==0) {
		rev[1]=1; for(i=2;i<=num;i++) rev[i]=rev[MO%i]*(MO-MO/i)%MO;
		revt[0]=1; for(i=1;i<=num;i++) revt[i]=revt[i-1]*rev[i]%MO;
	}
	ll ret=revt[C_];
	FOR(i,C_) ret = (ret * (N_-i))%MO;
	return ret;
}

void solve() {
	int x,y,z,i,j,p,rr,TM,TTC,dep,res,t;
	ll ret;
	
	for(i=j=1;i<=100;i++) {
		if(j*j<=i) j++;
		RT[i]=j-1;
	}
	
	GET2(&H,&T);
	ZERO(dp);
	dp[0][0][0]=1;
	
	// x:経過時間 y:ステップ数 z:位置
	FOR(x,90) FOR(y,90) FOR(z,H+1) {
		if(dp[x][y][z]==0) continue;
		for(j=2;j<100;j++) {
			if(x + RT[j] > T) break;
			if(z + j - RT[j] >= H) break;
			dp[x+RT[j]][y+1][z + j - RT[j]] = (dp[x+RT[j]][y+1][z + j - RT[j]] + dp[x][y][z]) % MO;
		}
	}
	
	//位置はどこでもいいので畳み込み
	ZERO(dp2);
	ret = 0;
	FOR(x,90) FOR(y,90) FOR(z,90) dp2[x][y] = (dp2[x][y]+dp[x][y][z])%MO;
	FOR(x,90) FOR(y,90) if(dp2[x][y]) ret = (ret + combi(T-x+y+1,y+1)*dp2[x][y]) %MO;
	
	_P("%lld\n",ret);
	
	
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

