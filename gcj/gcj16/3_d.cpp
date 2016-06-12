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

int N,L;
string G[101];
string B;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>L;
	FOR(i,N) cin>>G[i];
	cin>>B;
	FOR(i,N) if(G[i]==B) return _P("Case #%d: IMPOSSIBLE\n",_loop);
	
	if(L==1) {
		_P("Case #%d: %c? %c\n",_loop,B[0]^1,B[0]^1);
	}
	else {
		_P("Case #%d: ",_loop);
		
		FOR(i,L-1) _P("%s",B[i]=='1'?"01":"10");
		_P(" ");
		FOR(i,L) _P("%c?",B[i]^1);
		_P("\n");
	}
	
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


