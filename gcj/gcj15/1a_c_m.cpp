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

// this dows not work for Large input. O(N^3)

template<class C> C veccross(pair<C,C> p1,pair<C,C> p2,pair<C,C> p3) {
	p3.first-=p1.first;p2.first-=p1.first;
	p3.second-=p1.second;p2.second-=p1.second;
	return p3.first*p2.second-p2.first*p3.second;
}

int N;
pair<ll,ll> P[3030];
int ma[3030];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) cin>>P[i].first>>P[i].second,ma[i]=N;
	if(N<=2) FOR(i,N) ma[i]=0;
	
	FOR(i,N) {
		FOR(x,N) if(i!=x) {
			int pl=0,mi=0;
			
			FOR(y,N) if(y!=i && y!=x) {
				ll cr=veccross(P[i],P[x],P[y]);
				if(cr>0) pl++;
				if(cr<0) mi++;
			}
			ma[i]=min(ma[i],min(pl,mi));
		}
	}
	
	_P("Case #%d:\n",_loop);
	FOR(i,N) _P("%d\n",ma[i]);
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


