#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,A,B;
const int X=2000;
int U[X+2];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>A>>B;
	ZERO(U);
	FOR(i,N) cin>>U[i+1];
	
	for(i=N+1;i<=X;i++) {
		int num[X+2]={};
		num[i]=1;
		for(j=i;j>=1;j--) {
			if(num[j]<U[j]) break;
			x=num[j]-U[j];
			if(j>A) num[j-A]=min(num[j-A]+x,800);
			if(j>B) num[j-B]=min(num[j-B]+x,800);
		}
		
		if(j==0) break;
	}
	
	if(i==X+1) _P("Case #%d: IMPOSSIBLE\n",_loop);
	else _P("Case #%d: %d\n",_loop,i);
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


