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

int M;
int P[555];
ll N[555];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>M;
	ll S=0;
	FOR(i,M) {
		cin>>P[i]>>N[i];
		S+=P[i]*N[i];
	}
	ll ret=0;
	
	for(ll a=S;a>=max(1LL,S-500*8);a--) {
		ll sum=S;
		ll X=a;
		FOR(i,M) {
			ll num=N[i];
			while(num&&X%P[i]==0) num--, sum-=P[i], X/=P[i];
		}
		if(X==1&&a==sum) {
			ret=a;
			break;
		}
	}
	
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


