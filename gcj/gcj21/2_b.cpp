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

int B[1010101];
int N;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	int ma=0;
	for(x=1;x*x<=N;x++) if(N%x==0) {
		if(x>=3) ma=max(ma,B[N/x]);
		y=N/x;
		if(y>=3) ma=max(ma,B[N/y]);
		
	}
	_P("Case #%d: %d\n",_loop,ma);
}

void dfs(int cur,int sum, int num) {
	if(sum>1000000/3+5) return;
	B[sum]=max(B[sum],num);
	
	int i;
	for(i=cur*2;sum+i<=1000000/3+5;i+=cur) {
		dfs(i,sum+i,num+1);
	}
	
}

void init() {
	int i,j;
	
	dfs(1,1,1);
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


