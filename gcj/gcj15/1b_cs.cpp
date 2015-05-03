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

int N;
ll D[1010],H[1010],M[1010];
pair<ll,pair<ll,ll> > P[505000];
ll mi;

ll calc(ll t) {
	int i;
	ll ret=0;
	FOR(i,N) {
		if(P[i].first>t) ret++;
		ll dist=t/P[i].second.second;
		ret += (dist-(360-P[i].second.first))/360;
		if(ret>mi) return ret;
	}
	return ret;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) cin>>D[i]>>H[i]>>M[i];
	x=0;
	FOR(i,N) FOR(j,H[i]) {
		P[x].second.first=D[i];
		P[x].second.second=M[i]+j;
		P[x].first = (360-D[i])*(M[i]+j);
		x++;
	}
	N=x;
	sort(P,P+N);
	
	mi=N;
	FOR(i,N) mi=min(mi,calc(P[i].first));
	
	_P("Case #%d: %lld\n",_loop,mi);
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


