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

int N,Q;
vector<pair<int,int> > mp,mp2;
vector<int> lefts;
int next[100005][16];

void solve() {
	int x,y,i,j,res,TM,nc;
	int tx,ty,ng,LS;
	char cmd[100];
	ll p,cch;
	
	N=GETi();
	Q=GETi();
	
	FOR(i,N) {
		x=GETi();
		y=GETi();
		mp2.push_back(make_pair(y,-x));
	}
	MINUS(next);
	
	sort(mp2.begin(),mp2.end());
	int pl=-1000000001;
	j=0;
	FOR(i,N) {
		if(-mp2[i].second>pl) {
			pl=-mp2[i].second;
			mp.push_back(make_pair(mp2[i].first,-mp2[i].second));
			lefts.push_back(-mp2[i].second);
		}
	}
	N=mp.size();
	
	FOR(i,N) {
		vector<int>::iterator it=lower_bound(lefts.begin(),lefts.end(),mp[i].first);
		if(it!=lefts.end()) next[i][0]=it-lefts.begin();
	}
	
	FOR(j,14) FOR(i,N) if(next[i][j]>=0 && next[next[i][j]][j]>=0) next[i][j+1]=next[next[i][j]][j];
	
	FOR(i,Q) {
		int L=GETi();
		int R=GETi();
		
		vector<int>::iterator it=lower_bound(lefts.begin(),lefts.end(),L);
		res=0;
		if(it!=lefts.end()) {
			int cur=it-lefts.begin();
			if(mp[cur].first<=R) {
				res++;
				for(j=14;j>=0;j--) {
					while(next[cur][j]!=-1 && mp[next[cur][j]].first<=R) {
						res += 1<<j;
						cur = next[cur][j];
					}
				}
			}
		}
		_P("%d\n",res);
	}
	
	return;
}

int main(int argc,char** argv){
	struct timeval start,end,ts;
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&start,NULL);	solve();	gettimeofday(&end,NULL);
	ll span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	return 0;
}


