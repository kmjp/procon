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

int NP;
const int prime_max = 10000000;
int p[prime_max];
int cc;

void cprime() {
	
	int i,j;
	NP=0;
	for(i=2;i<prime_max;i++) {
		if(p[i]) continue;
		for(j=i*2;j<prime_max;j+=i) p[j]=i;
	}
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cprime();
	
	f=0;
	FOR(i,100) {
		int n=i+1;
		y =  (n-1)*n+41;
		y += n/41*((41-n%41)/41)*40;
		y += n/42*((99-n)/42)*((42-n%42)/42)*14;
		y += n/45*((99-n)/45)*((45-n%45)/45)*6;
		y += n/50*((100-n)/50)*cc;
		y += n/57*((99-n)/42)*18;
		y += n/66*((99-n)/33)*6;
		y += n/77*((99-n)/22)*4;
		y += n/83*((99-n)/16)*10;
		y += n/85*((99-n)/14)*6;
		y += n/88*((99-n)/11)*2;
		y += n/90*((99-n)/8)*2;
		y += n/92*((99-n)/7)*6;
		y += n/97*((99-n)/2)*18;
		x=0;
		
		_P("%d %d %d\n",n,y,p[y]);
		if(p[x+y]==0) f++;
		else _P("%d\t%d\t%d\t%d\t%d\n",n,x,y,x+y,p[x+y]);
	}
	_P("%d\n",f);
}


int main(int argc,char** argv){
	cc=atoi(argv[1]);
	solve();
	
	return 0;
}


