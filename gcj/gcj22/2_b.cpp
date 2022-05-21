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

int R;
int D[101010];

void solve(int _loop) {
	int f,i,j,k,l,x,y,r;
	
	cin>>R;
	
	ll fill=2*R+1;
	ZERO(S);
	for(x=1,y=R;x<=R;x++) {
		while(round(hypot(x,y))>R) y--;
		fill+=y;
	}
	
	ll sum=1;
	for(i=1;i<=R;i++) {
		D[i]=D[i-1];
		while(round(hypot(D[i]+1,D[i]+1))<=i) D[i]++;
		if(round(sqrt(1LL*i*i-1LL*D[i]*D[i]))==D[i]) {
			sum++;
			sum+=2*D[i];
		}
		else {
			sum+=2*D[i];
			if(round(hypot(D[i]+1,D[i]))==i) sum+=2;
		}
		
	}
	cout<<"Case #"<<_loop<<": "<<(fill-sum)*4<<endl;
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
		//fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


