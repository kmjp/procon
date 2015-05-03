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

map<ll,ll> M;

ll dodo(ll N) {
	if(N<10) return N;
	if(M.count(N)) return M[N];
	if(N%10==0) return M[N]=1+dodo(N-1);
	
	ll x=1;
	while(x*10<=N) x*=10;
	
	ll ret=min(N,dodo(x)+N-x);
	char ns[20];
	sprintf(ns,"%lld",N);
	string NS=ns;
	int L=NS.size();
	
	for(int i=1;i<=L;i++) {
		string pre=NS.substr(0,i);
		string post=NS.substr(i);
		reverse(pre.begin(),pre.end());
		ll tmp=atoll(pre.c_str())-1;
		if(post.size()) tmp+=atoll(post.c_str());
		ret = min(ret,dodo(x)+tmp+1);
	}
	
	return M[N]=ret;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	ll N;
	cin>>N;
	
	_P("Case #%d: %lld\n",_loop,dodo(N));
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


