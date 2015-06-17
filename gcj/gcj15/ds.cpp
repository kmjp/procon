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

int P;
ll E[20100],N[20100],T;
int num;
map<ll,int> M;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	T=num=0;
	cin>>P;
	M.clear();
	FOR(i,P) cin>>E[i];
	FOR(i,P) cin>>N[i], T+=N[i], M[E[i]]=N[i];
	
	while(1LL<<(num+1)<=T) num++;
	vector<ll> V,ret;
	int n0=0;
	while(1LL<<(n0+1)<=N[0]) n0++, ret.push_back(0);
	FOR(i,1<<n0) V.push_back(0);
	
	for(i=1;i<P;i++) {
		if(M[E[i]]==0) continue;
		int nn=M[E[i]]>>n0;
		FOR(j,nn) {
			x=V.size();
			ret.push_back(E[i]);
			FOR(y,x) V.push_back(V[y]+E[i]), M[V[y]+E[i]]--;
		}
	}
	
	_P("Case #%d:",_loop);
	FORR(r,ret) _P(" %lld",r);
	_P("\n");
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


