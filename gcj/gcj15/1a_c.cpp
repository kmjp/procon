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
pair<ll,ll> P[3030];
int ma[3030];
double deg[3030];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	double pi=acos(-1);
	cin>>N;
	FOR(i,N) cin>>P[i].first>>P[i].second,ma[i]=N;
	if(N<=2) FOR(i,N) ma[i]=0;
	
	FOR(i,N) {
		vector<double> V;
		FOR(x,N) if(i!=x) {
			ll dx=P[x].first-P[i].first;
			ll dy=P[x].second-P[i].second;
			ll g=__gcd(abs(dx),abs(dy));
			deg[x]=atan2(dx/g,dy/g);
			if(deg[x]<0) deg[x]+=2*pi;
			V.push_back(deg[x]);
			V.push_back(deg[x]+2*pi);
			V.push_back(deg[x]+4*pi);
		}
		sort(V.begin(),V.end());
		FOR(x,N) if(i!=x) {
			int pl=lower_bound(V.begin(),V.end(),deg[x]+pi)-lower_bound(V.begin(),V.end(),deg[x]+1e-10);
			int mi=lower_bound(V.begin(),V.end(),deg[x]+2*pi)-lower_bound(V.begin(),V.end(),deg[x]+pi+1e-10);
			ma[x]=min(ma[x],min(pl,mi));
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


