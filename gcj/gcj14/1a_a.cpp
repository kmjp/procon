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

int N,L;
ll S[200],T[200],E[200];
int ret=1000;

int okok(ll mask,int cur) {
	ll s2[200];
	ll t2[200];
	int i;
	FOR(i,N) s2[i]=(S[i]^mask)&((1LL<<cur)-1);
	FOR(i,N) t2[i]=T[i]&((1LL<<cur)-1);
	sort(s2,s2+N);
	sort(t2,t2+N);
	FOR(i,N) if(s2[i]!=t2[i]) return 0;
	return 1;
}

void dfs(int cur,ll mask) {
	if(okok(mask,cur)==0) return;
	if(cur==L) {
		ret=min(ret,__builtin_popcountll(mask));
		return;
	}
	if(__builtin_popcount(mask)>ret) return;
	
	dfs(cur+1,mask);
	dfs(cur+1,mask | (1LL<<cur));
}


void solve(int _loop) {
	int f,i,j,k,l,x,y;
	cin>>N>>L;
	string s;
	ZERO(S);
	ZERO(T);
	FOR(i,N) {
		cin>>s;
		FOR(j,L) if(s[j]=='1') S[i] |= 1LL<<j;
	}
	FOR(i,N) {
		cin>>s;
		FOR(j,L) if(s[j]=='1') T[i] |= 1LL<<j;
	}
	sort(S,S+N);
	sort(T,T+N);
	ret=1000;
	dfs(0,0);
	
	if(ret==1000) _P("Case #%d: NOT POSSIBLE\n",_loop);
	else  _P("Case #%d: %d\n",_loop,ret);
		
		
	

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


