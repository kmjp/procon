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

ll A,B;
ll gcd(ll a, ll b) { return (b==0)?a:gcd(b,a%b);}


vector<int> mult(vector<int>& l, vector<int>& r) {
	vector<int> res;
	int i;
	FOR(i,6) res.push_back(r[l[i]]);
	return res;
}

vector<int> pow(vector<int>& l, ll num) {
	vector<int> res,tmp;
	int i;
	FOR(i,6) res.push_back(i);
	tmp=l;
	while(num) {
		if(num&1) res = mult(res, tmp);
		tmp = mult(tmp, tmp);
		num >>= 1;
	}
	return res;
}

vector<int> calc(ll a, ll b, vector<int>& pata, vector<int>& patb) {
	if(b==0) return pata;
	if(a==0) return patb;
	if(a>=b){
		vector<int> tmp1=pow(pata,a/b);
		vector<int> tmp2=mult(tmp1,patb);
		return calc(a%b, b, pata,tmp2 );
	}
	else {
		vector<int> tmp3=pow(patb,b/a);
		vector<int> tmp4=mult(pata,tmp3);
		return calc(a, b%a, tmp4, patb);
	}
}

int num_ret(vector<int>& rotpat) {
	vector<int> res;
	int i,nl=1;
	FOR(i,6) res.push_back(rotpat[i]);
	
	while(1) {
		int ok=1;
		FOR(i,6) if(res[i]!=i) ok=0;
		if(ok) return nl;
		nl++;
		res = mult(res,rotpat);
	}
}

void solve() {
	int x,y,i,j,res,TM,nc;
	ll numloop;
	//0:ê⁄ín 1:ñ ÇÃîΩëŒ 2,3,4,5:è„âEâ∫ç∂
	int rotrpat[6] = {5,3,2,0,4,1};
	int rotupat[6] = {4,2,0,3,1,5};
	vector<int> rotr, rotu, rotpat;
	
	FOR(i,6) rotr.push_back(rotrpat[i]),rotu.push_back(rotupat[i]);
	
	
	scanf("%lld%lld",&A,&B);
	if(A==0 || B==0) {
		_P("%.7lf\n",4.0);
		return;
	}
	
	ll g = gcd(A,B);
	A/=g; B/=g;
	
	rotpat = calc(A,B,rotr,rotu);
	
	double nl = num_ret(rotpat);
	double DA = A, DB = B;
	_P("%.8lf\n",nl*sqrt(DA*DA+DB*DB));
	
	
	
	
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


