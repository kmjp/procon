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

int N;
ll A[201],B[101];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	ll S=0;
	FOR(i,N) {
		if(i<30) {
			A[i]=1<<i;
		}
		else {
			A[i]=(1<<29)+i;
		}
		cout<<A[i];
		S+=A[i];
		if(i<N-1) cout<<" ";
		else cout<<endl;
	}
	
	FOR(i,N) {
		cin>>A[i+N];
		S+=A[i+N];
	}
	S/=2;
	sort(A,A+2*N);
	vector<ll> R;
	for(i=2*N-1;i>=0;i--) if(S>=A[i]) {
		S-=A[i];
		R.push_back(A[i]);
	}
	FOR(i,R.size()) {
		cout<<R[i];
		if(i<R.size()-1) cout<<" ";
	}
	cout<<endl;
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


