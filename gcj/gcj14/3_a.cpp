#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sys/time.h>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

ll N,P,Q,R,S;
ll T[1000005];
ll sum[1000005];

void solve(int _loop) {
	int f,i,j,k,l,x,y,a,b;
	
	cin>>N>>P>>Q>>R>>S;
	FOR(i,N) {
		T[i]=(i*P+Q)%R+S;
		sum[i+1]=sum[i]+T[i];
	}
	
	ll ma=0;
	FOR(a,N) {
		ll mid=(sum[N]-sum[a])/2+sum[a];
		ll* p=upper_bound(sum,sum+N+1,mid);
		x=p-sum;
		
		FOR(i,5) {
			b=x+i-2;
			if(b>=a && b<N) {
				ll took=max(max(sum[a],sum[N]-sum[b+1]),sum[b+1]-sum[a]);
				ma=max(ma,sum[N]-took);
			}
		}
	}
	_P("Case #%d: %.12lf\n",_loop,ma/(double)sum[N]);
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


