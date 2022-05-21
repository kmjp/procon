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


int N,K;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>K;
	vector<pair<int,int>> cand;
	ll s=1;
	for(i=N;i>1;i-=2) {
		ll nex=s+(i-1)*4;
		FOR(j,4) {
			int a=nex+j*(i-3);
			int b=s+1+j*(i-1);
			if(a-b>2) cand.push_back({a-b-1,b});
		}
		s=nex;
	}
	
	int skip=N*N-1-K;
	int cur=1;
	vector<pair<int,int>> res;
	FORR2(a,b,cand) {
		if(cur>b) continue;
		if(skip>=a) {
			res.push_back({b,a+b+1});
			skip-=a;
			cur=a+b+1;
		}
	}
	
	
	if(skip) {
		cout<<"Case #"<<_loop<<": IMPOSSIBLE"<<endl;
	}
	else {
		cout<<"Case #"<<_loop<<": "<<res.size()<<endl;
		FORR2(a,b,res) cout<<a<<" "<<b<<endl;
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


