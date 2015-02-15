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

int M,N;
ll mo=1000000007;
string S[1001];
int cut[10];

int dodo() {
	string CS[10];
	int num=N;
	int i,x,s;
	
	FOR(i,M) {
		x=cut[i];
		s=0;
		while(s<CS[x].size()&& s<S[i].size()&&CS[x][s]==S[i][s]) s++;
		num+=S[i].size()-s;
		CS[x]=S[i];
	}
	return num;
}


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	int mask;
	int ma=0,num=0;
	
	cin>>M>>N;
	FOR(i,M) cin>>S[i];
	sort(S,S+M);
	FOR(mask,1<<(2*M)) {
		int have=0,ng=0;
		FOR(i,M) cut[i]=(mask>>(2*i))%4;
		FOR(i,M) have |= 1<<cut[i];
		FOR(i,M) if(cut[i]>=N) ng++;
		if(have!=(1<<N)-1) ng++;
		if(ng) continue;
		
		x=dodo();
		if(x>ma) ma=x,num=0;
		if(x==ma) num++;
	}
	
	_P("Case #%d: %d %d\n",_loop,ma,num);
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


