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

int C,D;
int X[1010];
vector<pair<int,int>> E[101];
int R[1010];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>C>>D;
	vector<int> num[101];
	int pat[2020]={};
	for(i=1;i<C;i++) {
		cin>>X[i];
		if(X[i]>0) pat[X[i]]++;
		else num[-X[i]].push_back(i);
	}
	
	int cur=1;
	for(int t=1;t<=2010;t++) {
		FORR(a,num[cur]) {
			X[a]=t;
			pat[t]++;
		}
		num[cur].clear();
		cur+=pat[t];
	}
	
	FOR(i,C) E[i].clear();
	_P("Case #%d:",_loop);
	FOR(i,D) {
		cin>>x>>y;
		_P(" %d",max(1,abs(X[x-1]-X[y-1])));
	}
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


