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

int R,C;
ll mo=1000000007;
ll dp[105][2][25];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>R>>C;
	ZERO(dp);
	dp[0][0][1]=dp[0][1][1]=1;
	
	FOR(i,R) {
		FOR(j,25) {
			// 22222
			(dp[i+1][0][j] += dp[i][1][j]) %= mo;
			// 122122
			// 122122
			if(C%3==0) (dp[i+2][0][3*j/__gcd(3,j)] += __gcd(3,j)*dp[i][1][j]) %= mo;
			// 112222
			// 222112
			if(C%6==0) (dp[i+2][0][6*j/__gcd(6,j)] += __gcd(6,j)*dp[i][1][j]) %= mo;
			// 2122
			// 2121
			// 2221
			if(C%4==0) (dp[i+3][0][4*j/__gcd(4,j)] += __gcd(4,j)*dp[i][1][j]) %= mo;
			// 3333
			// 3333
			(dp[i+2][1][j] += dp[i][0][j])%=mo;
		}
	}
	
	 ll tot=0;
	 FOR(i,25) tot+=dp[R][0][i]+dp[R][1][i];
	
	_P("Case #%d: %d\n",_loop,tot%mo);
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


