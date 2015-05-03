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

int dp[1010000];

ll rev(ll N) {
	ll v=0;
	while(N) v=v*10+N%10, N/=10;
	return v;
}


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	ll N;
	cin>>N;
	_P("Case #%d: %lld\n",_loop,dp[N]);
}

void init() {
	int i;
	priority_queue<pair<int,int> > Q;
	for(i=1;i<=1000000;i++) {
		dp[i]=i;
		Q.push(make_pair(-i,i));
	}
	while(Q.size()) {
		auto r=Q.top();
		Q.pop();
		int cur=r.second;
		int co=-r.first;
		if(co!=dp[cur]) continue;
		if(cur+1<=1000000 && dp[cur+1]>co+1) {
			dp[cur+1]=co+1;
			Q.push(make_pair(-dp[cur+1],cur+1));
		}
		int re=rev(cur);
		if(dp[re]>co+1) {
			dp[re]=co+1;
			Q.push(make_pair(-dp[re],re));
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


