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

const int NN=1000;
double P[2][NN][NN];

int N,A[1001];
int nok=0;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	cin>>N;
	double tot=0;
	FOR(i,N) {
		cin>>A[i];
		tot+=P[NN%2][A[i]][i];
	}
	if(tot>=0.993 && tot<=1.008) _P("Case #%d: GOOD\n",_loop);
	else _P("Case #%d: BAD\n",_loop);
	
}

void init() {
	int i,x,y;
	FOR(i,NN) P[0][i][i]=1;
	FOR(i,NN) {
		int cur=i%2,tar=cur^1;
		ZERO(P[tar]);
		FOR(x,NN) FOR(y,NN) {
			if(y!=i) P[tar][x][y]=P[cur][x][y]*(NN-1)/NN+P[cur][x][i]/NN;
			P[tar][x][i]+=P[cur][x][y]/NN;
		}
	}
	/*
	FOR(x,NN) {
		FOR(y,NN) _P("%.5lf ",P[0][x][y]);
		_P("\n");
	}
	*/
	
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


