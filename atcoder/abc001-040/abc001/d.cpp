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


int bm[24*12+1];

void solve() {
	int f,i,j,k,l, x,y;
	
	cin>>j;
	FOR(i,j) {
		scanf("%d-%d",&x,&y);
		x=(x/100)*60+(x%100);
		y=(y/100)*60+(y%100);
		for(x=x/5;x<(y+4)/5;x++) bm[x]=1;
	}
	
	i=0;
	while(i<24*12) {
		if(bm[i]==0) {
			i++;
			continue;
		}
		_P("%02d%02d-",i/12,i%12*5);
		while(i<24*12 && bm[i]) i++;
		_P("%02d%02d\n",i/12,i%12*5);
	}
	
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


