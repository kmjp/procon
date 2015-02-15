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
#else
#define DBG(...)
#define DV(...)
#endif


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


int T,K,D,m;
int data[20];
int hit[10000],np[1000000];


void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2,ng,mi;
	long long a,b,p,d;
	long long a0,a1,b0,b1,r0,r1,a2,b2,r2,q;
	double br,tb1,tb2,start,end;
	
	GET2(&D,&K);
	ZERO(data);
	
	mi=0;
	FOR(i,K){
		data[i] = GETi();
		if(mi<data[i]) mi=data[i];
	}
	m=1;
	FOR(i,D) m*=10;
	
	if(K==1) {
		_PE("Case #%d: I don't know.\n",_loop);
		return;
	}
	else if(K==2) {
		if(data[0]!=data[1]) {
			_PE("Case #%d: I don't know.\n",_loop);
		}
		else {
			_PE("Case #%d: %d\n",_loop,data[1]);
		}
		return;
	}
	else {
		
		if(data[0]==data[1]) {
			for(i=2;i<K;i++) {
				if(data[0]!=data[i]) {
					_PE("Case #%d: I don't know.\n",_loop);
					return;
				}
			}
			_PE("Case #%d: %d\n",_loop,data[0]);
			return;
			
		}
		if(data[1]==data[2]) {
			for(i=2;i<K;i++) {
				if(data[1]!=data[i]) {
					_PE("Case #%d: I don't know.\n",_loop);
					return;
				}
			}
			_PE("Case #%d: %d\n",_loop,data[1]);
			return;
		}	
		result = -1;
		FOR(p,m) {
			if(np[p]||p<=mi) continue;
			
			r0=((data[1]-data[0])+p)%p;
			r1=p;
			a0=b1=1; a1=b0=0;
			while(r1>0) {
				q = r0/r1;
				r2=r0%r1;
				a2=a0-q*a1;
				b2=b0-q*b1;
				r0=r1; r1=r2;
				a0=a1; a1=a2;
				b0=b1; b1=b2;
			}
			
			a0=(a0+p)%p;
			
			a = ((a0*(data[2]-data[1])%p)+p)%p;
			
			
			ng=0;
			d = data[0];
			b = (((data[1]-a*d)%p)+p)%p;
			if(a<0 || b<0 || a>=p || b>=p || (data[0]*a+b)%p!=data[1] || (data[1]*a+b)%p!=data[2]) {
				_E("uuuoooo %d %d %d %d %d\n",a,b,p,data[0],data[1]);
			}
			
			//_E("%d %d/%d %d %d %d [%d %d]\n",data[2]-data[1],p,m,a0,b0,r0,(data[0]*a+b)%p-data[1],(data[1]*a+b)%p-data[2]);
			
			for(i=0;i<K;i++) {
				d = (d*a+b)%p;
				if(i<K-1 && d != data[i+1]) {
					if(i==0){ _E("oooo %d %d %d %d %d\n",a,b,p,data[0],data[1]);}
					ng=1;
					break;
				}
			}
			if(ng) continue;
			if(result==-1){
				result=d;
				_E("%d %d %d %d\n",a,b,p,d);
			}
			else if(result!=d) {
				_E("err %d %d %d %d %d\n",a,b,p,d,result);
				_PE("Case #%d: I don't know.\n",_loop);
				return;
			}
		}
		
		if(result==-1) {
			_PE("Case #%d: I don't know.\n",_loop);
			return;
		}
		
		_PE("Case #%d: %d\n",_loop,result);
	}
}

void init() {
	int i,j;
	
	ZERO(np);
	np[0]=np[1]=1;
	for(i=2;i<1000000;i++) {
		if(np[i]==1) continue;
		
		for(j=i+i;j<1000000;j+=i) {
			np[j]=1;
		}
	}
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



