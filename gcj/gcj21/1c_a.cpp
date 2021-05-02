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

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	int N,K;
	vector<int> P;
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		P.push_back(x);
	}
	sort(ALL(P));
	vector<int> cand;
	cand.push_back(P[0]-1);
	cand.push_back(K-P.back());
	int ma=0;
	FOR(i,P.size()-1) {
		int d=P[i+1]-P[i];
		ma=max(ma,d-1);
		if(d>1) cand.push_back(d/2);
	}
	sort(ALL(cand));
	reverse(ALL(cand));
	ma=max(ma,cand[0]+cand[1]);
	
	_P("Case #%d: %.12lf\n",_loop,1.0*ma/K);
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


