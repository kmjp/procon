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

int B;
ll M;
int mat[60][60];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>B>>M;
	ZERO(mat);
	for(x=0;x<B-1;x++) for(y=x+1;y<B-1;y++) mat[x][y]=1;
	for(y=B-2;y>=0;y--) {
		ll v=(y==0)?1:(1LL<<y-1);
		if(M>=v) mat[y][B-1]=1, M-=v;
	}
	
	if(M==0) {
		_P("Case #%d: POSSIBLE\n",_loop);
		FOR(y,B) {
			FOR(x,B) _P("%d",mat[y][x]);
			_P("\n");
		}
	}
	else {
		_P("Case #%d: IMPOSSIBLE\n",_loop);
	}
	
	
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


