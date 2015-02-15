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
int func[26][2];
char str[2000];

int dofunc(char funcname, int cv,int loop) {
	int v,nv,id,nl;
	nl=loop;
	if(nl>2) nl=nl%2+2;
	
	v=cv;id=funcname-'a';
	while(nl--) {
		v = (func[id][0] & (~v)) |(func[id][1] & (v));
	}
	//_P("%c %d->%d(%d)\n",funcname,cv,v,loop);
	return v;
}

pair<int,char*> val(char* pc, int cv) {
	pair<int,char*> p;
	char fn;
	int v,loop,lh,rh;
	//_P("%s\n",pc);
	
	if(*pc=='x') return make_pair(cv,pc+1);
	if(*pc>='0' && *pc<='9') {
		v=0;
		while(*pc>='0' && *pc<='9') {
			v=v*10+(*pc-'0');
			pc++;
		}
		return make_pair(v,pc);
	}
	if(*pc>='a' && *pc<='j') {
		fn=*pc;
		pc++;
		loop=1;
		if(*pc=='^') {
			pc++;
			loop=0;
			while(*pc>='0' && *pc<='9') {
				loop=loop*10+(*pc-'0');
				pc++;
			}
		}
		pc++; // (
		p = val(pc,cv);
		pc=p.second+1; // )
		return make_pair(dofunc(fn,p.first,loop),pc);
	}
	if(*pc=='('){
		p = val(pc+1,cv);
		lh=p.first;
		pc=p.second;
		fn=*pc;
		
		p = val(pc+1,cv);
		rh=p.first;
		if(*pc=='|') return make_pair(lh|rh,p.second+1);
		if(*pc=='^') return make_pair(lh^rh,p.second+1);
		if(*pc=='&') return make_pair(lh&rh,p.second+1);
		_P("error op %s\n",pc);
	}
	
	_P("error %s\n",pc);
	
	return make_pair(0,pc);
}


void parse() {
	char* pc;
	pair<int,char*> vv;
	char fn = str[0]-'a';
	int i,v[2][2];
	pc=str+5;
	
	vv=val(pc,0);
	func[fn][0]=vv.first;
	vv=val(pc,0x7FFFFFFF);
	func[fn][1]=vv.first;
	//_P("%c %d %d\n",str[0],func[fn][0],func[fn][1]);
	_P("%c(x)=",str[0]);
	
	ZERO(v);
	FOR(i,31) {
		if((func[fn][0] & (1<<i)) && (func[fn][1] & (1<<i))) v[1][1]|=1<<i;
		if(((func[fn][0] & (1<<i))==0) && (func[fn][1] & (1<<i))) v[0][1]|=1<<i;
		if((func[fn][0] & (1<<i)) && ((func[fn][1] & (1<<i))==0)) v[1][0]|=1<<i;
	}
	
	_P("(%d|((x&%d)^%d))\n",v[1][1],v[0][1]|v[1][0],v[1][0]);
	
}


void solve() {
	int x,y,i,j,p,rr,TM,TTC;
	
	N=GETi();
	FOR(i,N) {
		GETs(str);
		parse();
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

