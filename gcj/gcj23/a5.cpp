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

string C;

int from[3],to[3];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>C;
	FORR(c,C) {
		if(c=='P') c=0;
		if(c=='R') c=1;
		if(c=='S') c=2;
	}
	int mi=1<<30;
	FOR(i,3) {
		from[0]=from[1]=from[2]=1<<30;
		from[i]=C[0]!=i;
		
		for(j=1;j<C.size();j++) {
			to[0]=to[1]=to[2]=1<<30;
			FOR(x,3) FOR(y,3) if(x!=y) {
				to[y]=min(to[y],from[x]+(y!=C[j]));
			}
			swap(from,to);
		}
		FOR(j,3) if(j!=i) mi=min(mi,from[j]);
	}
	cout<<"Case #"<<_loop<<": "<<mi<<endl;
	
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


