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

int N,M;
int TS[201];
int TT[201];
int rm[100001];
vector<int> rmv;
vector<pair<int,int> > TR;
ll num[1000][1000]; // num[y][x] x‚Ü‚Å2ŒÂˆÈãAy‚Ü‚Å1ŒÂ

void solve() {
	int x,y,i,j,rr,TM,nc;
	int tx,ty,ng,LS;
	char cmd[100];
	ll p,cch;
	
	N=GETi();
	M=GETi();
	ng=0;
	
	rmv.clear();
	ZERO(rm);
	FOR(i,M) {
		TS[i]=GETi();
		TT[i]=GETi();
		if(TS[i]==1) ng |= 1;
		if(TT[i]==N) ng |= 2;
		rmv.push_back(TS[i]);
		rmv.push_back(TT[i]);
	}
	sort(rmv.begin(),rmv.end());
	
	
	if(ng!=3) {
		_P("0\n");
		return;
	}
	sort(rmv.begin(),rmv.end());
	rmv.erase(unique(rmv.begin(), rmv.end()), rmv.end());
	
	FOR(i,rmv.size()) {
		if(i==0) rm[rmv[0]]=1;
		else if(rmv[i]==rmv[i-1]+1) rm[rmv[i]]=rm[rmv[i-1]]+1;
		else rm[rmv[i]]=rm[rmv[i-1]]+2;
		LS=rm[rmv[i]];
	}
	
	TR.clear();
	FOR(i,M) TR.push_back(make_pair(rm[TS[i]],rm[TT[i]]));
	sort(TR.begin(),TR.end());
	
	ZERO(num);
	num[0][0]=1;
	FOR(i,TR.size()) {
		int s = TR[i].first;
		int t = TR[i].second;
		
		for(y=LS;y>=s-1;y--) {
			for(x=LS;x>=y;x--) {
				if(!num[y][x]) continue;
				if(t<=y) {
					num[y][x] +=num[y][x];
					num[y][x] %= 1000000007;
				}
				else if(t<=x) {
					num[t][x] +=num[y][x];
					num[t][x] %= 1000000007;
				}
				else {
					num[x][t] +=num[y][x];
					num[x][t] %= 1000000007;
				}
			}
		}
	}
	_P("%lld\n",num[LS][LS]%1000000007);
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


