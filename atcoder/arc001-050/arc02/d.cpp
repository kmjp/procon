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

int W,H;
char str[2002][2002];
vector<string> strs;

void dostep(string& st,int& dist,int& no,int& nx,int& stepo, int& stepx) {
	int i,lo,fx,farx,faro;
	//数を数えつつ、残り距離が1になるまでのステップを探る
	no=nx=stepo=stepx=0;
	lo=fx=-1;
	FOR(i,st.size()) {
		if(st[i]=='o') lo=i;
		if(st[i]=='x') if(fx<0) fx=i;
	}
	
	//残り1ますになるまでの距離
	dist = fx-lo-2;
	
	//残り1マス・2マスになるまでのステップ
	faro=lo+dist/2;
	farx=fx-dist/2;
	
	for(i=st.size()-1;i>=0;i--) if(st[i]=='o') stepo += faro-(no++)-i;
	FOR(i,st.size()) if(st[i]=='x') stepx += i-(farx+(nx++));
	
}

void solve() {
	int f,r,i,j,k,l;
	int x,y,mx,my;
	int mino, minx;
	
	GET2(&H,&W);
	FOR(y,H) GETs(str[y]);
	
	//触れずにゴールできるか？
	mino=minx=3000;
	FOR(y,H) {
		for(x=W-1;x>=0;x--) {
			if(str[y][x]=='x') break;
			if(str[y][x]=='o') mino=min(mino, W-1-x);
		}
		FOR(x,W) {
			if(str[y][x]=='o') break;
			if(str[y][x]=='x') minx=min(minx, x);
		}
	}
	
	if(mino<=minx && mino<3000) {
		_P("o\n");
		return;
	}
	if(minx<mino) {
		_P("x\n");
		return;
	}
	
	//oとxの対を調べる
	FOR(y,H) {
		int so=-1,sx=-1;
		string s=string(str[y]);
		FOR(x,W) {
			if(str[y][x]=='o') {
				if(sx>=0) {
					strs.push_back(string(s,so,sx-so+1));
					so=x;
				}
				if(so==-1) so=x;
				sx=-1;
			}
			if(str[y][x]=='x') sx=x;
		}
		if(sx>=0) strs.push_back(string(s,so,sx-so+1));
	}
	
	ll tso,tsx;
	tso=tsx=0;
	vector<pair<int, pair<int,int> > > cand;
	FOR(i,strs.size()) {
		int dist, no, nx, stepo, stepx;
		dostep(strs[i],dist,no,nx,stepo,stepx);
		
		tso+=stepo;
		tsx+=stepx;
		//先手を取った方がよい
		if(dist%2) cand.push_back(make_pair(no+nx,make_pair(no,nx)));
	}
	
	//効果の大きい順に先手を取る
	sort(cand.begin(),cand.end());
	reverse(cand.begin(),cand.end());
	j=0;
	FOR(i,cand.size()) {
		if(j==0) tso += cand[i].second.first;
		else tsx += cand[i].second.second;
		j^=1;
	}
	
	
	if(tso>tsx) _P("o\n");
	else  _P("x\n");
	
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}
