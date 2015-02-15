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

int P,Q,N;
int H[105],G[101];
int dpdp[101][11][1001];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>P>>Q>>N;
	ZERO(H);
	ZERO(G);
	FOR(i,N) cin>>H[i]>>G[i];
	FILL_INT(dpdp,-1000000000);
	dpdp[0][0][1]=0;

	FOR(i,N) {
		for(j=0;j*Q<H[i];j++) {
			// attack?
			FOR(k,1001) {
				if(j*Q+(k-1)*P<H[i] && j*Q+k*P>=H[i]) {
					FOR(x,1001) if(x>=k) {
						dpdp[i+1][0][x-k] = max(dpdp[i+1][0][x-k], dpdp[i][j][x]+G[i]);
					}
				}
			}
			
			// no attack
			FOR(k,1001) {
				if((j+1)*Q>=H[i]) dpdp[i+1][0][k+1] = max(dpdp[i+1][0][k+1], dpdp[i][j][k]);
				else dpdp[i][j+1][k+1] = max(dpdp[i][j+1][k+1], dpdp[i][j][k]);
			}
		}
	}
	
	int ret=0;
	FOR(j,11) FOR(k,1001) ret=max(ret,dpdp[N][j][k]);
	
	_P("Case #%d: %d\n",_loop,ret);
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


