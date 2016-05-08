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

int N;
int P[27];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	vector<pair<int,int>> V;
	int sum=0;
	FOR(i,N) cin>>x, V.push_back({x,'A'+i}), sum+=x;
	_P("Case #%d:",_loop);
	
	while(sum>0) {
		sort(ALL(V));
		reverse(ALL(V));
		//FORR(r,V) _P("%c/%d ",r.second,r.first);
		//_P(" : %d\n",sum);
		if((V[0].first-1)*2<=sum-1 && V[1].first*2<=sum-1) {
			_P(" %c",V[0].second);
			V[0].first--;
			sum--;
		}
		else if(V[0].first>1 && (V[0].first-2)*2<=sum-2 && V[1].first*2<=sum-2) {
			_P(" %c%c",V[0].second,V[0].second);
			V[0].first-=2;
			sum-=2;
		}
		else if((V[0].first-1)*2<=sum-2 && V[1].first>0 && (V.size()==2 || V[2].first*2<=sum-2)) {
			_P(" %c%c",V[0].second,V[1].second);
			V[0].first--;
			V[1].first--;
			sum-=2;
		}
		else {
			_P("failed\n");
			break;
		}
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


