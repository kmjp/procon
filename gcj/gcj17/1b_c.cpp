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

int N,Q;
int E[101],S[101];
ll D[101][101];
double T[101][101];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>Q;
	FOR(i,N) cin>>E[i]>>S[i];
	FOR(y,N) {
		FOR(x,N) {
			cin>>D[y][x];
			if(y==x) D[y][x]=0;
			else if(D[y][x]==-1) D[y][x]=1LL<<50;
		}
	}
	int z;
	FOR(z,N) FOR(x,N) FOR(y,N) D[x][y]=min(D[x][y],D[x][z]+D[z][y]);
	FOR(y,N) {
		FOR(x,N) {
			if(D[y][x]>E[y]) T[y][x]=1e15;
			else T[y][x]=D[y][x]*1.0/S[y];
		}
	}
	
	FOR(z,N) FOR(x,N) FOR(y,N) T[x][y]=min(T[x][y],T[x][z]+T[z][y]);
	_P("Case #%d:",_loop);
	FOR(i,Q) {
		cin>>x>>y;
		_P(" %.12lf",T[x-1][y-1]);
	}
	_P("\n");
	
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


