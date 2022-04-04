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

int C[3][4];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	FOR(y,3) FOR(x,4) cin>>C[y][x];
	int r=1000000;
	FOR(x,4) {
		C[0][x]=min({C[0][x],C[1][x],C[2][x],r});
		r-=C[0][x];
	}
	if(r) {
		cout<<"Case #"<<_loop<<": IMPOSSIBLE"<<endl;
	}
	else {
		cout<<"Case #"<<_loop<<": "<<C[0][0]<<" "<<C[0][1]<<" "<<C[0][2]<<" "<<C[0][3]<<endl;
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


