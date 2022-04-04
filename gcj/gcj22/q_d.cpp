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

int N;
int F[101010];
int P[101010];
vector<int> M[101010];
void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N+1) {
		M[i].clear();
	}
	FOR(i,N) {
		cin>>F[i+1];
	}
	FOR(i,N) {
		cin>>P[i+1];
	}
	ll ret=0;
	for(i=N;i>=1;i--) {
		if(M[i].empty()) {
			M[i].push_back(0);
		}
		sort(ALL(M[i]));
		FOR(j,M[i].size()) {
			if(j==0) M[P[i]].push_back(max(M[i][0],F[i]));
			else ret+=M[i][j];
		}
	}
	
	FORR(a,M[0]) ret+=a;
	
	cout<<"Case #"<<_loop<<": "<<ret<<endl;
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


