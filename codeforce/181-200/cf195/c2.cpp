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


int N;
vector<ll> A;

void solve() {
	int f,r,i,j,k,l,x,y,tx,ty,aa[5];

	cin>>N;
	FOR(i,N) A.push_back(GETi());

	FOR(j,31) {
		x=1<<(30-j);
		y=0x7FFFFFFF;
		f=0;
		FOR(i,N) if(A[i]&x) y&=A[i],f++;
		if(y%x==0) {
			_P("%d\n",f);
			FOR(i,N) if(A[i]&x) _P("%d ",A[i]);
			_P("\n");
			return;
		}
	}
	return;
}

int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


