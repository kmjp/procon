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
#include <sys/time.h>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------


// g++ -O2 -Wl,-stack,5000000 c.cpp

int W,H,B;
int R[511][511];
struct edge { int to, capacity, reve;};
const int MV = 101000;
vector<edge> E[MV];

class MaxFlow {
public:
	int vis[MV];
	
	void init() { for(int i=0;i<MV;i++) E[i].clear();}
	MaxFlow() {init();}
	void add_edge(int x,int y, int cap) {
		E[x].push_back((edge){y,cap,E[y].size()});
		E[y].push_back((edge){x,0, E[x].size()-1}); /* rev edge */
	}
	
	int dfs(int from,int to,int cf) {
		int i,tf;
		if(from==to) return cf;
		vis[from]=1;
		FOR(i,E[from].size()) {
			edge& e=E[from][i];
			if(vis[e.to]==0 && e.capacity>0 && (tf = dfs(e.to,to,min(cf,e.capacity)))>0) {
				e.capacity -= tf;
				E[e.to][e.reve].capacity += tf;
				return tf;
			}
		}
		return 0;
	}
	
	int maxflow(int from, int to) {
		int fl=0,tf;
		while(1) {
			ZERO(vis);
			if((tf = dfs(from,to,1<<29))==0) return fl;
			fl+=tf;
		}
	}
};

MaxFlow mf;
void solve(int _loop) {
	int f,i,j,k,l,x,y,x0,y0,x1,y1;
	
	cin>>W>>H>>B;
	ZERO(R);
	FOR(i,B) {
		cin>>x0>>y0>>x1>>y1;
		for(x=x0;x<=x1;x++) for(y=y0;y<=y1;y++) R[y][x]=1;
	}
	mf.init();
	FOR(i,W) if(R[0][i]==0) mf.add_edge(100001,i*2,1);
	FOR(i,W) if(R[H-1][i]==0) mf.add_edge((H-1)*200+i*2+1,100002,1);
	FOR(y,H) {
		FOR(x,W) if(R[y][x]==0) {
			mf.add_edge(y*200+x*2,y*200+x*2+1,1);
			if(x>0 && R[y][x-1]==0) mf.add_edge(y*200+x*2+1,y*200+(x-1)*2,1);
			if(x<W-1 && R[y][x+1]==0) mf.add_edge(y*200+x*2+1,y*200+(x+1)*2,1);
			if(y<H-1 && R[y+1][x]==0) mf.add_edge(y*200+x*2+1,y*200+x*2+200,1);
			if(y>0 && R[y-1][x]==0) mf.add_edge(y*200+x*2+1,y*200+x*2-200,1);
		}
	}
	_P("Case #%d: %d\n",_loop,mf.maxflow(100001,100002));
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


