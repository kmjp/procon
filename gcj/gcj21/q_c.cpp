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

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	int N,C;
	cin>>N>>C;
	C-=(N-1);
	int L[101];
	if(C<0) {
		_P("Case #%d: IMPOSSIBLE\n",_loop);
		return;
	}
	
	FOR(i,N) L[i]=i+1;
	for(i=N-2;i>=0;i--) {
		x=min(C,N-1-i);
		reverse(L+i,L+i+x+1);
		C-=x;
	}
	if(C!=0) {
		_P("Case #%d: IMPOSSIBLE\n",_loop);
		return;
	}
	
	_P("Case #%d:",_loop);
	FOR(i,N) _P(" %d",L[i]);
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


