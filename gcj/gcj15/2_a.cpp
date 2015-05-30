#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[101];
int cost;
int L[101][101];
int R[101][101];
int T[101][101];
int B[101][101];



void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	FOR(y,H) {
		L[y][0]=-1;
		for(x=1;x<W;x++) {
			if(S[y][x-1]=='.') L[y][x]=L[y][x-1];
			else L[y][x]=x-1;
		}
		R[y][W-1]=W;
		for(x=W-2;x>=0;x--) {
			if(S[y][x+1]=='.') R[y][x]=R[y][x+1];
			else R[y][x]=x+1;
		}
	}
	FOR(x,W) {
		T[0][x]=-1;
		for(y=1;y<H;y++) {
			if(S[y-1][x]=='.') T[y][x]=T[y-1][x];
			else T[y][x]=y-1;
		}
		B[H-1][x]=H;
		for(y=H-2;y>=0;y--) {
			if(S[y+1][x]=='.') B[y][x]=B[y+1][x];
			else B[y][x]=y+1;
		}
	}
	cost=0;
	FOR(y,H) FOR(x,W) if(S[y][x]!='.') {
		int cy=y,cx=x;
		if(S[y][x]=='^') cy=T[y][x];
		else if(S[y][x]=='v') cy=B[y][x];
		else if(S[y][x]=='<') cx=L[y][x];
		else if(S[y][x]=='>') cx=R[y][x];
		
		if(cy>=0 && cy<H && cx>=0 && cx<W) continue;
		if(L[y][x]>=0 || R[y][x]<W || T[y][x]>=0 || B[y][x]<H) {
			cost++;
		}
		else {
			return _P("Case #%d: IMPOSSIBLE\n",_loop);
		}
	}
	
	
	_P("Case #%d: %d\n",_loop,cost);
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


