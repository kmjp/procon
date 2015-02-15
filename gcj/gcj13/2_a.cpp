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
#define _Dm(fmt) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__)
#define _D(fmt, ...) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

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


ll N,M;
ll O[1001],E[1001],P[1001];
pair<pair<ll,ll>,ll> hoge[1001];
vector<pair<ll,int> > EV;

ll cost(ll s,ll e) {
	return ((e-s)*(e-s-1)/2)%1000002013;
}

void solve(int _loop) {
	int i,j,x,y,z,ne=0;
	
	EV.clear();
	
	cin >> N>>M;
	ll tot=0;
	FOR(i,M) {
		cin>>O[i]>>E[i]>>P[i];
		hoge[i].first.first=O[i];
		hoge[i].first.second=E[i];
		hoge[i].second=P[i];
		tot = (tot+P[i]*cost(O[i],E[i]))%1000002013;
	}
	sort(hoge,hoge+M);
	FOR(i,M) {
		P[i]=hoge[i].second;
		EV.push_back(make_pair(hoge[i].first.second,i));
	}
	
	sort(EV.begin(),EV.end());
	ll tt2=0;
	ITR(eit,EV) {
		ll rr=hoge[eit->second].second;
		
		for(y=M-1;y>=0;y--) {
			if(rr==0) break;
			if(hoge[y].first.first > eit->first) continue;
			ll red=min(rr,P[y]);
			tt2=(tt2+red*cost(hoge[y].first.first,eit->first))%1000002013;
			rr-=red;
			P[y]-=red;
		}
	}
	
	
	_PE("Case #%d: %lld\n",_loop,(((tt2-tot)%1000002013)+1000002013)%1000002013);
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
	
	GET1(&loops);
	gets(tmpline);
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL);
		solve(loop);
		gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		_E("                                     time: %lld ms\n",span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



