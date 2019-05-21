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
ll C[11],J[11];

ll miP,miQ;
ll maP,maQ;

pair<ll,ll> hoge(ll p1,ll q1,ll p2,ll q2) {
	if(q1==0) q1=1,p1=1LL<<30;
	if(q2==0) q2=1,p2=1LL<<30;
	if(p1<q1 && p2>q2) {
		return {1,1};
	}
	else if(p1>=q1) {
		ll d=p1/q1;
		auto p=hoge(p1-d*q1,q1,p2-d*q2,q2);
		p.first+=d*p.second;
		return p;
	}
	else {
		auto p=hoge(q2,p2,q1,p1);
		return {p.second,p.first};
	}
	
	
}


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) cin>>C[i]>>J[i];
	
	miP=maQ=1;
	miQ=maP=1LL<<30;
	
	FOR(y,N) FOR(x,y) {
		if(C[x]>=C[y] && J[x]>=J[y]) return _P("Case #%d: IMPOSSIBLE\n",_loop);
		if(C[x]>C[y]) {
			ll p=C[x]-C[y];
			ll q=J[y]-J[x];
			if(p*miQ>q*miP) miP=p, miQ=q;
		}
		else if(J[x]>J[y]) {
			ll p=C[y]-C[x];
			ll q=J[x]-J[y];
			if(p*maQ<q*maP) maP=p, maQ=q;
		}
	}
	if(miP*maQ>=maP*miQ) return _P("Case #%d: IMPOSSIBLE\n",_loop);
	
	auto p=hoge(miP,miQ,maP,maQ);
	_P("Case #%d: %lld %lld\n",_loop,p.second,p.first);
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


