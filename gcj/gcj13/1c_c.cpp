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
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

const int MD=676061;
int N;
int D[1001],NN[1001],W[1001],E[1001],S[1001],DD[1001],DP[1001],DS[1001];
vector<int> C[MD];

const int BITL=22;
map<int,int> P2I;
int CS[1<<(BITL+1)];

int update(int cur,int L,int R,int v) {
	int bl=0;
	if(L==R) return v+1;
	
	while(cur>=1<<(bl+1)) bl++;
	int tl=(cur-(1<<bl))<<(BITL-bl-1);
	int tr=(cur-(1<<bl)+1)<<(BITL-bl-1);
	int tm=(tl+tr)/2;
	//_P("%x %x %x : %x %x %x %d %d\n",cur,L,R,tl,tr,tm,CS[cur],v);
	
	if(tl==L && tr==R && CS[cur]>=0) {
		return CS[cur]=max(CS[cur],v);
	}
	else {
		if(CS[cur]>=0) {
			if(CS[cur]>=v) return CS[cur];
			CS[(1<<(bl+1))+(tl>>(BITL-bl-2))]=CS[cur];
			CS[(1<<(bl+1))+(tm>>(BITL-bl-2))]=CS[cur];
		}
		CS[cur]=-1;
		if(L<tm) update((1<<(bl+1))+(tl>>(BITL-bl-2)),L,min(tm,R),v);
		if(R>=tm) update((1<<(bl+1))+(tm>>(BITL-bl-2)),max(L,tm),R,v);
	}
}

int query(int cur,int L,int R,int v) {
	int bl=0,r;
	if(L==R) return 0;
	if(CS[cur]>=0) return (v>CS[cur])?1:0;
	
	while(cur>=1<<(bl+1)) bl++;
	int tl=(cur-(1<<bl))<<(BITL-bl-1);
	int tr=(cur-(1<<bl)+1)<<(BITL-bl-1);
	int tm=(tl+tr)/2;
	//_P("%x %x %x : %x %x %x %d %d\n",cur,L,R,tl,tr,tm,CS[cur],v);
	
	return ((L<tm)&&query((1<<(bl+1))+(tl>>(BITL-bl-2)),L,min(tm,R),v)) || 
		((R>=tm) &&query((1<<(bl+1))+(tm>>(BITL-bl-2)),max(L,tm),R,v));
}


void solve(int _loop) {
	int i,j,x,y,ne=0;
	
	N=GETi();
	FOR(i,N) cin>>D[i]>>NN[i]>>W[i]>>E[i]>>S[i]>>DD[i]>>DP[i]>>DS[i];
	FOR(i,MD) C[i].clear();
	P2I.clear();
	FOR(i,N) FOR(j,NN[i]) C[D[i]+j*DD[i]].push_back(i);
	FOR(i,N) FOR(j,NN[i]) P2I[W[i]+j*DP[i]]=P2I[E[i]+j*DP[i]]=0;
	
	i=0;
	for(map<int,int>::iterator mit=P2I.begin();mit!=P2I.end();mit++) mit->second = i++;
	
	MINUS(CS);
	CS[1]=0;
	
	int res=0;
	FOR(i,MD) {
		//if(C[i].size()) _E("%d %d %d\n",_loop,i,C[i].size());
		FOR(x,C[i].size()) {
			//_E("%d %d %x %x %d\n",i,C[i][x],P2I[W[C[i][x]]],P2I[E[C[i][x]]],S[C[i][x]]);
			if(query(1,P2I[W[C[i][x]]],P2I[E[C[i][x]]],S[C[i][x]])) {
				res++;
				S[C[i][x]]=-S[C[i][x]];
			}
		}
		FOR(x,C[i].size()) {
			j=C[i][x];
			//_E("**%d %d %x %x %d\n",i,j,W[j],E[j],S[j]);
			//_P("%d %d\n",W[j],E[j]);
			if(S[j]<0) {
				S[j]=-S[j];
				update(1,P2I[W[j]],P2I[E[j]],S[j]);
			}
			
			D[j]+=DD[j];
			S[j]+=DS[j];
			W[j]+=DP[j];
			E[j]+=DP[j];
		}
	}

	_PE("Case #%d: %d\n",_loop,res);
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



