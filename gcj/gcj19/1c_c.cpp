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

int H,W;
string S[15];

int gr[16][16][16][16];

int hoge(int y1,int y2,int x1,int x2) {
	if(y2<=y1||x2<=x1) return 0;
	if(gr[y1][y2][x1][x2]>=0) return gr[y1][y2][x1][x2];
	int x,y;
	set<int> T;
	for(y=y1;y<y2;y++) {
		int num=0;
		for(x=x1;x<x2;x++) num+=S[y][x]=='#';
		if(num==0) T.insert(hoge(y1,y,x1,x2)^hoge(y+1,y2,x1,x2));
	}
	for(x=x1;x<x2;x++) {
		int num=0;
		for(y=y1;y<y2;y++) num+=S[y][x]=='#';
		if(num==0) T.insert(hoge(y1,y2,x1,x)^hoge(y1,y2,x+1,x2));
	}
	gr[y1][y2][x1][x2]=0;
	while(T.count(gr[y1][y2][x1][x2])) gr[y1][y2][x1][x2]++;
	return gr[y1][y2][x1][x2];
	
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	MINUS(gr);
	int ok=0;
	FOR(y,H) {
		if(count(ALL(S[y]),'#')==0 && (hoge(0,y,0,W)^hoge(y+1,H,0,W))==0) ok+=W;
	}
	FOR(x,W) {
		int num=0;
		FOR(y,H) num+=S[y][x]=='#';
		if(num==0 && (hoge(0,H,0,x)^hoge(0,H,x+1,W))==0) ok+=H;
	}
	
	_P("Case #%d: %d\n",_loop,ok);
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


