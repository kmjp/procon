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

typedef signed long long s64;
typedef unsigned long long u64;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
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
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

char str[100];
int ok[10],mok;
s64 P;

// 2ケタの実現方法
int num[100];
int numpat[100][10];

int ml=99999;
int tpat[10];

int from[20][100];
int pketa[20][100];

int pat_keta(int keta,int c) {
	int mn=0,k,tc,t;
	
	t = 0;
	for(k = keta; k>=0; k--) {
		
		if(k==0) {
			tc = c;
		}
		else {
			tc = c - from[k][c]/10;
		}
		mn = max(mn, num[tc]);
		t+=mn;
		if(k==0) break;
		c = from[k][c];
		if(c==-1) return 99999;
	}
	// + と =
	t += mn;
	return t;
	
}

int okn(){
	s64 a=P;
	while(a>0) {
		if(ok[a%10]==0) return 0;
		a /= 10;
	}
	return 1;
}

void dfs(int goal,int sum,int c,int depth) {
	int i,r;
	if(sum > goal) return ;
	if(sum == goal) {
		if(depth < ml) {
			ml=depth;
			memcpy(numpat[goal],tpat,40);
		}
		
		return;
	}
	
	for(i=c;i>0;i--) {
		if(ok[i]==0) continue;
		tpat[i]++;
		dfs(goal,sum+i,i,depth+1);
		tpat[i]--;
	}
}

void initnum(){
	int i;
	
	FOR(i,100) {
		num[i]=-1;
		if(i > mok*9) continue;
		ZERO(tpat);
		ml=99999;
		dfs(i,0,9,1);
		num[i] = ml;
	}
}

int minr = 999999;
int mk=0, mi=0;

void reg_result(int k,int i) {
	if(minr > pketa[k][i]) {
		minr = pketa[k][i];
		mk=k;
		mi=i;
	}
}

void output(int k,int c) {
	//各桁の残り数
	int rnum[20][10];
	int i,kk,ok,first=1,tc;
	
	for(kk=k;kk>=0;kk--) {
		tc = c;
		if(kk>0) tc -= from[kk][c]/10;
		memcpy(rnum[kk],numpat[tc],40);
		
		if(kk>0)
			c = from[kk][c];
	}
	
	while(1){
		//最上位桁を探す
		while(k>=0) {
			ok=0;
			FOR(i,10) {
				if(rnum[k][i]) ok=1;
			}
			if(ok) break;
			k--;
		}
		if(k<0) break;
		if(!first) _P("+");
		first=0;
		for(kk=k;kk>=0;kk--) {
			FOR(i,10) {
				if(rnum[kk][i]){
					_P("%d",i);
					rnum[kk][i]--;
					break;
				}
			}
			if(i==10) {
				_P("0");
			}
		}
	}
	
	_P("=\n");
}

void solve() {
	int f,t,r;
	int m,d,i,j,dd,carry,cp,keta,nc,nt,of,org;
	s64 T,M,pret;
	
	mok=0;
	GETs(str);
	ZERO(ok);
	FOR(i,strlen(str)){
		ok[str[i]-'0']++;
		if(str[i]-'0' > mok) mok=str[i]-'0';
	}
	
	scanf("%lld",&P);
	if(okn()) {
		_P("%lld\n",P);
		return;
	}
	
	ZERO(numpat);
	MINUS(num);
	initnum();
	
	carry = 1;
	keta = 0;
	T=P;
	pret=0;
	while(T>0) {
		FOR(i,100){
			pketa[keta][i]=99999;
			from[keta][i]=-1;
		}
		cp = 0;
		FOR(nc,10){
			if(!(carry & (1<<nc))) continue;
			FOR(i,100){
				org = i-nc;
				if(org <0 || num[org]==-1) continue;
				if(i % 10 != T % 10) continue;
				if(i > T) continue;
				
				cp |= 1<<(i/10);
				
				of = from[keta][i];
				from[keta][i] = nc*10+pret;
				r = pat_keta(keta,i);
				if(r < pketa[keta][i]){
					pketa[keta][i] = r;
					if(i==T) reg_result(keta,i);
				}
				else {
					from[keta][i] = of;
				}
			}
		}
		carry = cp;
		/*
		FOR(i,100){
			if(from[keta][i]>=0)
				_P("%d:%d(%d) ",i,from[keta][i],pketa[keta][i]);
		}
		_P("[%d]\n",keta);
		*/
		
		keta++;
		pret = T%10;
		T/=10;
	}
	
	output(mk,mi);
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
	
	init();
	solve();
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	//_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



