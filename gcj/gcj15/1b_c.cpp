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
pair<ll,ll> P[505000];
int slower[505000];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	x=0;
	FOR(i,N) {
		cin>>D[i]>>H[i]>>M[i];
		FOR(j,H[i]) {
			P[x].second=M[i]+j;
			P[x].first=(360-D[i])*(M[i]+j);
			x++;
		}
	}
	N=x;
	sort(P,P+N);
	
	for(i=N-1;i>=0;i--) {
		if(P[i].first==P[i+1].first) slower[i]=slower[i+1];
		else slower[i]=N-1-i;
	}
	
	ll mi=N;
	ll faster=0;
	priority_queue<pair<ll,ll> > Q;
	FOR(i,N) {
		while(Q.size()) {
			auto r=Q.top();
			if(-r.first>P[i].first) break;
			if(++faster>N) break;
			Q.pop();
			Q.push(make_pair(r.first-360LL*r.second,r.second));
		}
		
		Q.push(make_pair(-P[i].first-360LL*P[i].second,P[i].second));
		mi=min(mi,faster + slower[i]);
		if(faster>N) break;
	}
	
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


