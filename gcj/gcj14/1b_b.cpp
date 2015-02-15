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

ll A,B,K;

ll dodo(ll A,ll B,int dig) {
	ll D=1LL<<dig;
	if(dig==-1) return 1;
	ll ret=0;
	if(K&D) {
		if(A>=D && B>=D) ret=dodo(A-D,B-D,dig-1);
		if(A>=D) ret+=(A-D+1)*(min(B,D-1)+1);
		if(B>=D) ret+=(B-D+1)*(min(A,D-1)+1);
		ret+=(min(A,D-1)+1)*(min(B,D-1)+1);
	}
	else {
		if(A>=D) ret+=dodo(A-D,min(B,D-1),dig-1);
		if(B>=D) ret+=dodo(min(A,D-1),B-D,dig-1);
		ret+=dodo(min(A,D-1),min(B,D-1),dig-1);
	}
	return ret;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>A>>B>>K;
	A--,B--,K--;
	
	_P("Case #%d: %lld\n",_loop,dodo(A,B,29));
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


