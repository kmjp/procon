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

ll R,N,M,K;
vector<pair<ll,map<ll,int> > > C;

void dfs(int L,ll V) {
	if(L==N) {
		map<ll,int> TM;
		
		int num[10];
		ZERO(num);
		ll v=V;
		while(v) {
			num[v%10]++;
			v/=10;
		}
		ll tp=1;
		for(int i=2;i<=M;i++) while(num[i]>1) tp*=num[i]--;
		TM[0]=tp;
		
		for(int mask=0;mask<(1<<N);mask++) {
			ll t=1;
			ll v=V;
			for(int i=0;i<N;i++) {
				if(mask&(1<<i)) t *= v%10;
				v /= 10;
			}
			TM[t]++;
		}
		
		C.push_back(make_pair(V,TM));
		return;
	}
	
	for(int i=max(2,(int)(V%10));i<=M;i++) dfs(L+1,V*10+i);
}


void solve2(vector<ll>& V) {
	int i,x;
	ll mv=0;
	double ma=0;
	vector<ll> c;
	
	FOR(i,C.size()) {
		double sc=1.0/C[i].second[0];
		FOR(x,V.size()) {
			ll tv=V[x];
			if(C[i].second.find(tv)==C[i].second.end()) {
				sc=0;
				break;
			}
			sc *= C[i].second[tv];
		}
		
		if(sc>ma) {
			ma=sc;
			mv=C[i].first;
		}
	}
	_P("%lld\n",mv);
}

void solve(int _loop) {
	int i,j,x,y,ne=0;
	
	_PE("Case #%d:\n",_loop);
	
	cin >> R >> N >> M >> K;
	C.clear();
	dfs(0,0);
	
	FOR(y,R) {
		_E("%d\n",y);
		vector<ll> V;
		FOR(x,K) V.push_back(GETi());
		sort(V.begin(),V.end());
		solve2(V);
	}
	
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



