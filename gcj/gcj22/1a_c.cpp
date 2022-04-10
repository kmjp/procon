#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int E,W,X[102][102];
int dp[101][101];

int dfs(int L,int R) {
	int del[101]={};
	int y,x;
	
	if(L+1>=R) return 0;
	
	if(dp[L][R]>=0) return dp[L][R];
	
	int ret=0;
	FOR(x,W) {
		del[x]=101;
		for(y=L;y<R;y++) del[x]=min(del[x],X[y][x]);
		ret+=del[x];
	}
	int mi=0;
	
	for(int M=L+1;M<R;M++) mi=max(mi,ret+dfs(L,M)+dfs(M,R));
	return dp[L][R]=mi;
	
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	MINUS(dp);
	cin>>E>>W;
	ZERO(X);
	int ret=0;
	FOR(y,E) FOR(x,W) {
		cin>>X[y][x];
		ret+=X[y][x];
	}
	ret-=dfs(0,E);
	
	cout<<"Case #"<<_loop<<": "<<(ret*2)<<endl;
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


