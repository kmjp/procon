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

int A[2];
int NG[2][1540];

int from[1500][2][2];
int to[1500][2][2];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	ZERO(NG);
	cin>>A[0]>>A[1];
	FOR(i,2) {
		while(A[i]--) {
			cin>>x>>y;
			while(x<y) NG[i][x++]=1;
		}
	}
	FOR(i,1440) from[i][0][0]=from[i][0][1]=from[i][1][0]=from[i][1][1]=5050;
	from[0][0][0]=from[0][1][1]=0;
	FOR(i,1440) {
		FOR(j,1440) to[j][0][0]=to[j][0][1]=to[j][1][0]=to[j][1][1]=5050;
		FOR(x,1440) {
			y=i-x;
			if(y<0) continue;
			FOR(j,2) {
				// x->x
				if(NG[0][i]==0 && x<720) to[x+1][j][0]=min(to[x+1][j][0],from[x][j][0]);
				// x->y
				if(NG[1][i]==0 && y<720) to[x][j][1]=min(to[x][j][1],from[x][j][0]+1);
				// y->x
				if(NG[0][i]==0 && x<720) to[x+1][j][0]=min(to[x+1][j][0],from[x][j][1]+1);
				// y->y
				if(NG[1][i]==0 && y<720) to[x][j][1]=min(to[x][j][1],from[x][j][1]);
			}
		}
		swap(from,to);
	}
	
	int ret=5050;
	ret=min(ret,from[720][0][0]);
	ret=min(ret,from[720][0][1]+1);
	ret=min(ret,from[720][1][0]+1);
	ret=min(ret,from[720][1][1]);
	
	_P("Case #%d: %d\n",_loop,ret);
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


