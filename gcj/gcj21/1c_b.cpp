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

ll Y;

int D[1010101];
ll p10[20];
set<ll> S;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>Y;
	Y++;
	ll ret=*S.lower_bound(Y);
	
	int d=0;
	ll a=Y;
	while(a) a/=10,d++;
	
	if(d==19) {
		;
	}
	else if(d%2==1) {
		ret=min(ret,p10[d]+p10[d/2]+1);
		ll a=(p10[d/2]-1)*p10[d/2+1]+p10[d/2];
		if(a>=Y) ret=min(ret,a);
	}
	else {
		ll U=Y/p10[d/2];
		ll V=Y%p10[d/2];
		
		if(U!=p10[d/2]-1) {
			if(V<=U+1) {
				ret=min(ret,U*p10[d/2]+(U+1));
			}
			else if(U!=p10[d/2]-2) {
				ret=min(ret,(U+1)*p10[d/2]+(U+2));
			}
		}
		
	}
	
	_P("Case #%d: %lld\n",_loop,ret);
}

void init() {
	int i;
	
	p10[0]=1;
	FOR(i,19) p10[i+1]=p10[i]*10;
	for(i=1;i<1010000;i++) {
		int x=i;
		while(x) {
			D[i]++;
			x/=10;
		}
	}
	for(i=1;i<1000000;i++) {
		ll a=i;
		ll cur=i+1;
		while(a<=2LL<<60) {
			if(a!=i) S.insert(a);
			assert(D[cur]);
			if((2LL<<60)/p10[D[cur]]<a) break;
			a=a*p10[D[cur]]+cur;
			cur++;
		}
	}
	
	
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


