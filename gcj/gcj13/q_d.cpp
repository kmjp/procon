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

int N,K;
int NK[201];
vector<int> key[201];
vector<int> k2v[201];
vector<int> mat[201];
vector<int> res;
int CK[201];
int op[201],vis[201];

int check(){
	int i,j;
	queue<int> Q;
	ZERO(vis);
	FOR(i,N) if(!op[i] && !vis[i] && CK[NK[i]]>0) {
		Q.push(i);
		vis[i]=1;
	}
	
	while(!Q.empty()) {
		int cur=Q.front();
		Q.pop();
		
		FOR(j,mat[cur].size()) {
			int tar=mat[cur][j];
			if(!op[tar] && !vis[tar]) {
				Q.push(tar);
				vis[tar]=1;
			}
		}
	}
	
	FOR(i,N) if(!op[i] && !vis[i]) return 0;
	return 1;
}

void solve(int _loop) {
	int i,x,y,z,j;
	
	GET2(&K,&N);
	ZERO(CK);
	FOR(i,K) CK[GETi()-1]++;
	FOR(i,201) {
		key[i].clear();
		k2v[i].clear();
		mat[i].clear();
	}
	
	FOR(i,N) {
		NK[i]=GETi()-1;
		k2v[NK[i]].push_back(i);
		key[i].resize(GETi());
		FOR(x,key[i].size()) key[i][x]=GETi()-1;
	}
	
	ZERO(mat);
	FOR(x,N) FOR(y,key[x].size())
		FOR(i,k2v[key[x][y]].size()) mat[x].push_back(k2v[key[x][y]][i]);
	
	_PE("Case #%d:",_loop);
	
	ZERO(op);
	if(check()==0) {
		_PE(" IMPOSSIBLE\n");
	}
	else {
		res.clear();
		
		FOR(x,N) {
			FOR(y,N) {
				if(op[y]) continue;
				if(CK[NK[y]]==0) continue;
				
				CK[NK[y]]--;
				FOR(i,key[y].size()) CK[key[y][i]]++;
				op[y]=1;
				if(check()==1) {
					res.push_back(y);
					break;
				}
				op[y]=0;
				FOR(i,key[y].size()) CK[key[y][i]]--;
				CK[NK[y]]++;
			}
			if(y==N) {
				_PE(" IMPOSSIBLE\n");
				return;
			}
		}
		
		FOR(x,res.size()) {_PE(" %d",res[x]+1);}
		_PE("\n");
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



