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
int N,M;
ll FX[5001],FY[5001];
ll SX[100001],SY[100001];

class G {
public:
	static const int MV = 5000;
	vector<int> E[MV], RE[MV], NUM;
	vector<vector<int> > SC;
	int NV,vis[MV],GR[MV];
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear(); }}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){ SC[c].clear(); revdfs(NUM[i],c++);}
		SC.resize(c);
	}
};

vector<int> smap[25][25];

void solve() {
	int f,r,i,j,k,l,res;
	G g;
	
	N=GETi();
	FOR(i,N) { FX[i]=GETi()+1200000000LL; FY[i]=GETi()+1200000000LL;}
	
	M=GETi();
	FOR(i,M) {
		SX[i]=GETi()+1200000000LL; SY[i]=GETi()+1200000000LL;
		smap[SX[i]/100000000][SY[i]/100000000].push_back(i);
	}
	
	g.init(N);
	FOR(j,N) {
		ull mind=(1ULL<<63)-1;
		if(M<2000 || N<=30) {
			FOR(i,M) mind = min(mind,(ull)((FX[j]-SX[i])*(FX[j]-SX[i]))+(ull)((FY[j]-SY[i])*(FY[j]-SY[i])));
		}
		else {
			/* rand */
			int tx = FX[j]/100000000;
			int ty = FY[j]/100000000;
			FOR(k,5) FOR(l,5) FOR(i,smap[tx+(k-2)][ty+(l-2)].size()) {
				int s=smap[tx+(k-2)][ty+(l-2)][i];
				mind = min(mind,(ull)((FX[j]-SX[s])*(FX[j]-SX[s]))+(ull)((FY[j]-SY[s])*(FY[j]-SY[s])));
			}
		}
		
		FOR(k,N) {
			ull dist=(ull)((FX[j]-FX[k])*(FX[j]-FX[k]))+(ull)((FY[j]-FY[k])*(FY[j]-FY[k]));
			if(j!=k && dist<mind) g.add_edge(j,k);
		}
	}
	
	g.scc();
	res=0;
	int vis[5001];
	ZERO(vis);
	FOR(i,N){
		if(vis[i]) continue;
		FOR(j, g.SC[g.GR[i]].size()) vis[g.SC[g.GR[i]][j]]=1;
		int top=1;
		FOR(j, g.SC[g.GR[i]].size()) {
			int id=g.SC[g.GR[i]][j];
			FOR(k,g.RE[id].size()) {
				if(g.GR[g.RE[id][k]] != g.GR[i]) {
					top=0; break;
				}
			}
			if(top==0) break;
		}
		res+=top;
	}
	
	_P("%d\n",res);
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
	
	gettimeofday(&start,NULL);
	init();
	solve();
	gettimeofday(&end,NULL);
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	
	return 0;
	
}



