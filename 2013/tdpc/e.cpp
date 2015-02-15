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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

ll D;
int L;
string N;
ll dpdp[2][100];
ll mo=1000000007;
int nd[10001][110];

void solve() {
	int f,r,i,j,k,l, x,y,z;
	
	cin>>D>>N;
	L=N.size();
	
	nd[0][0]=1;
	FOR(i,10000) {
		FOR(x,D) {
			if(nd[i][x]==0) continue;
			FOR(y,10) nd[i+1][(x+y)%D] = (nd[i+1][(x+y)%D] + nd[i][x]) % mo;
		}
	}
	
	dpdp[0][0]=1;
	FOR(i,L) {
		int cur=i%2;
		int tar=1^cur;
		ZERO(dpdp[tar]);
		x=N[L-1-i]-'0';
		FOR(y,D) {
			dpdp[tar][(x+y)%D] += dpdp[cur][y];
			dpdp[tar][(x+y)%D] %= mo;
		}
		
		FOR(x,N[L-1-i]-'0') {
			FOR(y,D) {
				dpdp[tar][(x+y)%D] += nd[i][y];
				dpdp[tar][(x+y)%D] %= mo;
			}
		}
	}
	
	// 0‚Ì•ª
	dpdp[L%2][0] += (mo-1);
	dpdp[L%2][0] %= mo;
	cout << dpdp[L%2][0] << endl;
	return;
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


