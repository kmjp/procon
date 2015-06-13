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

int N,K;
ll S[1010];
ll A[1010],ma[1010],mi[1010];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>K;
	FOR(i,N-K+1) cin>>S[i];
	ZERO(A);
	ZERO(ma);
	ZERO(mi);
	for(i=K;i<N;i++) A[i]=A[i-K]+S[i-K+1]-S[i-K], ma[i%K]=max(ma[i%K],A[i]),mi[i%K]=min(mi[i%K],A[i]);
	
	ll ret=0;
	int num=0;
	ll mv=S[0];
	FOR(i,K) {
		mv += mi[i];
		ma[i]-=mi[i];
		ret=max(ret,ma[i]);
	}
	
	mv=((mv%K)+K)%K;
	ll fre=0;
	FOR(i,K) fre += ret-ma[i];
	if(fre<mv) ret++;
	
	_P("Case #%d: %lld\n",_loop,ret);
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


