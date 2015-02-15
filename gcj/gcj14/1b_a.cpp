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

int N;
string S[101];
string S2[101];
int num[101][101];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	ZERO(num);
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		S2[i]="";
		FOR(j,S[i].size()) {
			if((j==0 || S[i][j]!=S[i][j-1])) S2[i]+=S[i][j];
			num[i][S2[i].size()-1]++;
		}
	}
	
	FOR(x,N) FOR(y,N) if(S2[x]!=S2[y]) return _P("Case #%d: Fegla Won\n",_loop);
	
	int ret=0;
	FOR(i,S2[0].size()) {
		int mi=100000;
		FOR(j,101) {
			int sum=0;
			FOR(x,N) sum+=abs(num[x][i]-j);
			mi=min(mi,sum);
		}
		ret+=mi;
	}
	
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


