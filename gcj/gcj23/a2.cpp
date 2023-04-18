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

int M,R,N;
int X[101010];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>M>>R>>N;
	int num=0;
	int TR=0;
	int prex=-1;
	
	FOR(i,N) {
		cin>>X[i];
	}
	FOR(i,N) {
		x=X[i];
		if(x-R>TR) {
			if(prex==-1) break;
			num++;
			TR=prex+R;
			if(x-R>TR) break;
		}
		prex=x;
	}
	if(TR<M&&prex!=-1) {
		TR=prex+R;
		num++;
	}
	
	if(i<N||TR<M) {
		cout<<"Case #"<<_loop<<": IMPOSSIBLE"<<endl;
	}
	else {
		cout<<"Case #"<<_loop<<": "<<num<<endl;
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


