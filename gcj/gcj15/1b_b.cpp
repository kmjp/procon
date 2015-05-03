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

int H,W,N;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>H>>W>>N;
	if(H>W) swap(H,W);
	
	vector<int> S[2];
	
	FOR(y,H) FOR(x,W) {
		i=0;
		if(x>0) i++;
		if(x<W-1) i++;
		if(y>0) i++;
		if(y<H-1) i++;
		S[(y+x)%2].push_back(i);
	}
	
	int mi=100000;
	FOR(i,2) {
		x=N-S[i^1].size();
		sort(S[i].begin(),S[i].end());
		if(x<=0) mi=0;
		else mi=min(mi,accumulate(S[i].begin(),S[i].begin()+x,0));
	}
	
	_P("Case #%d: %d\n",_loop,mi);
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


