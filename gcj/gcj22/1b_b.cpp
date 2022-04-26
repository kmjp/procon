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

int N,P;
int X[1010][1010];

ll from[2];
ll S[2],T[2];
ll to[2];


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>P;
	S[0]=S[1]=0;
	from[0]=from[1]=0;
	FOR(y,N) {
		T[0]=1LL<<60;
		T[1]=0;
		FOR(x,P) {
			cin>>i;
			T[0]=min(T[0],(ll)i);
			T[1]=max(T[1],(ll)i);
		}
		
		to[0]=min(from[0]+abs(S[0]-T[1])+abs(T[1]-T[0]),from[1]+abs(S[1]-T[1])+abs(T[1]-T[0]));
		to[1]=min(from[0]+abs(S[0]-T[0])+abs(T[1]-T[0]),from[1]+abs(S[1]-T[0])+abs(T[1]-T[0]));
		swap(from,to);
		swap(S,T);
	}
	
	
	cout<<"Case #"<<_loop<<": "<<min(from[0],from[1])<<endl;
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


