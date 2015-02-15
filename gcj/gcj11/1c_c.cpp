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

int N;
vector<long long> F;
long long L,H;
long long LCM[10001],GCD[10001];
const long long MA = (1LL<<60);


#define GCD_TYPE long long
GCD_TYPE gcd(GCD_TYPE a, GCD_TYPE b) {
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}

long long okok(long long lc,long long gc) {
	long long min=MA;
	if(H<lc) return MA;
	if(gc<L) return MA;
	
	long long tmp=lc;
	long long div = gc/lc;
	//_P("%lld %lld %lld %lld\n",lc,gc,L,H);
	for(long long mult=1;lc*mult*mult<=gc;mult++) {
		tmp = mult*lc;
		if(gc%tmp!=0) continue;
		if(tmp>=L && tmp<=H){
			//_P("%lld\n",tmp);
			return tmp;
		}
		if((gc/lc)%mult==0) {
			tmp = lc*(gc/lc/mult);
			if(tmp>=L && tmp<=H){
				//_P("%lld\n",tmp);
				min=tmp;
			}
		}
	}
	return min;
}


void solve(int _loop) {
	int i,j,k,result,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei,mv,mi;
	double br,tb1,tb2,start,end;
	long long res;
	N=GETi();
	scanf("%lld",&L);
	scanf("%lld",&H);
	F.clear();
	FOR(i,N) {
		scanf("%lld",&res);
		F.push_back(res);
	}
	F.push_back(1);
	sort(F.begin(),F.end());
	F.erase(unique(F.begin(),F.end()),F.end());
	N = F.size();
	FOR(i,N) {
	}
	
	//GCD
	FOR(i,N) {
		int j = N-1-i;
		if(j==N-1) GCD[j]=F[j];
		else {
			GCD[j]=gcd(GCD[j+1],F[j]);
		}
	}
	//LCD
	FOR(i,N) {
		if(i==0) LCM[i]=F[i];
		else {
			if(LCM[i-1]>=MA) LCM[i]=MA;
			else {
				long long g = gcd(LCM[i-1],F[i]);
				LCM[i]=LCM[i-1]/g*F[i];
				if(LCM[i]>MA || LCM[i]<LCM[i-1]) LCM[i]=MA;
			}
		}
	}
	res=MA;
	FOR(i,N-1) {
		long long lc=LCM[i];
		long long gc=GCD[i+1];
		if(lc>=MA) continue;
		if(gc%lc!=0) continue;
		
		long long tres = okok(lc,gc);
		if(tres<res) res=tres;
	}
	
	// N-1;
	if(LCM[N-1] <= H) {
		long long l1 = (L+LCM[N-1])/LCM[N-1];
		long long h1 = H/LCM[N-1];
		if(h1>=l1 && l1*LCM[N-1] < res) res=l1*LCM[N-1];
	}
	if(res==MA){ _PE("Case #%d: NO\n",_loop);}
	else{  _PE("Case #%d: %lld\n",_loop,res);}
	
	// small
	/*
	for(res=L;res<=H;res++) {
		int ok=1;
		FOR(i,N) {
			if(F[i]%res != 0 && res%F[i] != 0) {
				ok=0;
				break;
			}
		}
		if(ok==1) {
			_PE("Case #%d: %lld\n",_loop,res);
			return;
		}
	}
	_PE("Case #%d: NO\n",_loop);
	return;
	*/
	
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



