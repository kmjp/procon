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

int N,M,K;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M>>K;
	int ma=1000;
	int mask;
	FOR(mask,1<<(N*M)) {
		int vis[20][20];
		ZERO(vis);
		queue<int> Q;
		if(__builtin_popcount(mask)>=ma) continue;
		FOR(x,M) if((mask&(1<<x))==0) vis[0][x]=1, Q.push(x);
		FOR(x,M) if((mask&(1<<((N-1)*M+x)))==0) vis[N-1][x]=1, Q.push((N-1)*M+x);
		for(y=1;y<N-1;y++) if((mask&(1<<(M*y)))==0) vis[y][0]=1, Q.push(M*y);
		for(y=1;y<N-1;y++) if((mask&(1<<(M*y+(M-1))))==0) vis[y][M-1]=1, Q.push(M*y+(M-1));
		while(!Q.empty()) {
			int k=Q.front();
			Q.pop();
			int cx=k%M,cy=k/M;
			FOR(i,4) {
				int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
				int tx=cx+dx[i],ty=cy+dy[i];
				if(tx<0 || tx>=M || ty<0 || ty>=N) continue;
				if(vis[ty][tx]) continue;
				if(mask&(1<<(ty*M+tx))) continue;
				vis[ty][tx]=1;
				Q.push(ty*M+tx);
			}
		}
		int cnt=N*M;
		FOR(y,N) FOR(x,M) cnt-=vis[y][x];
		if(cnt==K) ma=__builtin_popcount(mask);
	}
	
	_P("Case #%d: %d\n",_loop,ma);
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


