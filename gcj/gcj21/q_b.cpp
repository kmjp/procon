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
	int X,Y;
	string S;
	cin>>X>>Y>>S;
	ll from[2]={1LL<<60,1LL<<60};
	if(S[0]=='C'||S[0]=='?') from[0]=0;
	if(S[0]=='J'||S[0]=='?') from[1]=0;
	S.erase(S.begin());
	FORR(c,S) {
		ll to[2];
		if(c=='C') {
			to[0]=min(from[0],from[1]+Y);
			to[1]=1LL<<60;
		}
		else if(c=='J') {
			to[0]=1LL<<60;
			to[1]=min(from[0]+X,from[1]);
		}
		else {
			to[0]=min(from[0],from[1]+Y);
			to[1]=min(from[0]+X,from[1]);
		}
		swap(from,to);
	}
	
	
	_P("Case #%d: %lld\n",_loop, min(from[0],from[1]));
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


