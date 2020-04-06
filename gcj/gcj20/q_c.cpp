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



void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	int N;
	vector<int> ev[1444];
	cin>>N;
	string S(N,'.');

	FOR(i,N) {
		cin>>x>>y;
		ev[x].push_back(N+i);
		ev[y].push_back(i);
	}
	
	int mask=0;
	int C[2]={-1,-1};
	FOR(i,1442) {
		sort(ALL(ev[i]));
		FORR(e,ev[i]) {
			if(e<N) {
				if(C[0]==e) C[0]=-1;
				else C[1]=-1;
			}
			else {
				x=e-N;
				if(C[0]==-1) {
					C[0]=x;
					S[x]='C';
				}
				else if(C[1]==-1) {
					C[1]=x;
					S[x]='J';
				}
				else {
					_P("Case #%d: IMPOSSIBLE\n",_loop);
					return;
				}
			}
		}
		ev[i].clear();
	}
	
	
	_P("Case #%d: %s\n",_loop,S.c_str());
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


