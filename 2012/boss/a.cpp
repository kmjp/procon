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

int W,H;
set<pair<int, int> > mine[26];
vector<pair<int, int> > minenei[26][26];

int canmask[51][51];
ll tok[51][51][51];
int neimask[26];
vector<int> nei[26];

vector<int> mlist;
int revid[26];

char str[100][100];
int npat,newest,mask;

pair<int,int> dfsc[26];

void enum_pcan(int f,int t) {
	set<pair<int, int> >::iterator fit,tit;
	vector<pair<int, int> >::iterator it2;
	
	for(fit=mine[f].begin();fit!=mine[f].end();fit++) for(tit=mine[t].begin();tit!=mine[t].end();tit++) {
		bool ok=true;
		
		// 境界のマスだけチェック
		for(it2=minenei[f][t].begin();ok&&it2!=minenei[f][t].end();it2++) {
			int fd = abs(fit->first-it2->first)+abs(fit->second-it2->second);
			int td = abs(tit->first-it2->first)+abs(tit->second-it2->second);
			if(td<fd) ok=false;
		}
		for(it2=minenei[t][f].begin();ok&&it2!=minenei[t][f].end();it2++) {
			int fd = abs(fit->first-it2->first)+abs(fit->second-it2->second);
			int td = abs(tit->first-it2->first)+abs(tit->second-it2->second);
			if(fd<=td) ok=false;
		}
		
		if(ok){
			tok[fit->first][fit->second][tit->first] |= 1LL<<tit->second;
			tok[tit->first][tit->second][fit->first] |= 1LL<<fit->second;
			canmask[fit->first][fit->second]|=1<<t;
			canmask[tit->first][tit->second]|=1<<f;
		}
	}
}

void output() {
	int x;
	FOR(x,26) if(!mine[x].empty()) {
		_P("%c %d %d\n",x+'a',dfsc[x].first,dfsc[x].second);
	}
}

void dfs(int id, vector<pair<int,int> > *pc) {
	vector<pair<int,int> > npc[26];
	int x,y,cur;
	
	if(id==mlist.size()) {
		output();
		exit(0);
	}
	
	cur = mlist[id];
	FOR(x,26) if(!(neimask[cur] & (1<<x))) npc[x] = pc[x];

	for(vector<pair<int, int> >::iterator fit=pc[cur].begin();fit!=pc[cur].end();fit++) {
		bool ok=true;
		FOR(x,26) {
			if(revid[x] < id || !(neimask[cur] & (1<<x))) continue;
			
			npc[x].clear();
			FOR(y,pc[x].size()) {
				if(tok[fit->first][fit->second][pc[x][y].first] & (1LL<<pc[x][y].second)) {
					npc[x].push_back(pc[x][y]);
				}
			}
			if(npc[x].empty()) {
				ok=false;
				break;
			}
		}
		if(ok) {
			dfsc[cur]=*fit;
			dfs(id+1,npc);
		}
	}
	return;
	
}

void dfs_c(int cur, int& mask) {
	int x;
	
	mask |= 1<<cur;
	revid[cur]=mlist.size();
	mlist.push_back(cur);
	FOR(x,26) {
		if(!(mask & (1<<cur)) && (neimask[cur] & (1<<x))) dfs_c(x,mask);
	}
}

void solve() {
	int x,y,i,j,res,TM,nc;
	
	W=GETi();
	H=GETi();
	FOR(y,H) {
		GETs(str[y]);
		FOR(x,W) {
			int c=str[y][x]-'a';
			if(mine[c].empty()){ npat++; newest=c;}
			mine[c].insert(make_pair(x,y));
		}
	}
	
	FOR(y,H) FOR(x,W) {
		if(x<W-1 && str[y][x]!=str[y][x+1]) {
			minenei[str[y][x]-'a'][str[y][x+1]-'a'].push_back(make_pair(x,y));
			neimask[str[y][x]-'a'] |= 1<<(str[y][x+1]-'a');
			minenei[str[y][x+1]-'a'][str[y][x]-'a'].push_back(make_pair(x+1,y));
			neimask[str[y][x+1]-'a'] |= 1<<(str[y][x]-'a');
		}
		if(y<H-1 && str[y][x]!=str[y+1][x]){
			minenei[str[y][x]-'a'][str[y+1][x]-'a'].push_back(make_pair(x,y));
			neimask[str[y][x]-'a'] |= 1<<(str[y+1][x]-'a');
			minenei[str[y+1][x]-'a'][str[y][x]-'a'].push_back(make_pair(x,y+1));
			neimask[str[y+1][x]-'a'] |= 1<<(str[y][x]-'a');
		}
	}
	
	// 1種類なら終わる
	if(npat==1) {
		_P("%c %d %d\n",newest+'a',0,0);
		return;
	}
	
	FOR(x,26) FOR(y,26) if(x<y && (neimask[x] & (1<<y))) enum_pcan(x,y);
	//候補を絞る
	int mask=0;
	vector<pair<int, int> > pcan[26];
	
	FOR(x,26) {
		revid[x]=-1;
		if(mine[x].empty()) mask |= 1<<x;
		for(set<pair<int, int> >::iterator fit=mine[x].begin();fit!=mine[x].end();fit++) {
			if(canmask[fit->first][fit->second] == neimask[x]) pcan[x].push_back(*fit);
		}
		FOR(y,26) if(neimask[x] & (1<<y)) nei[x].push_back(y);
	}
	
	FOR(x,26) if((mask & (1<<x))==0) dfs_c(x,mask);
	dfs(0, pcan);
	
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


