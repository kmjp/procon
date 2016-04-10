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

set<ll> did;

ll base(int mask,int b) {
	ll v=0;
	while(mask) {
		v=v*b+(mask&1);
		mask>>=1;
	}
	return v;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	int N,J;
	cin>>N>>J;
	
	_P("Case #%d:\n",_loop);
	did.clear();
	for(i=2;i<=N&&J;i++) if(N%i==0) {
		for(int mask=0;J&&mask<1<<(i-2);mask++) {
			ll tmask=(1LL<<(i-1)) | 1 | (mask<<1);
			ll dmask=0;
			
			FOR(x,N/i) dmask=(dmask<<i) | tmask;
			if(did.count(dmask)) continue;
			did.insert(dmask);
			J--;
			
			FOR(x,N) _P("%d",(dmask>>x)&1);
			for(x=2;x<=10;x++) _P(" %lld",base(tmask,x));
			_P("\n");
		}
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


