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

int N,M;
int C[101];
int cost[101];
int I[101][101];
int P[101][101];

double dpdp[2048];

void solve() {
	int f,i,j,k,l, x,y;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>C[i]>>cost[i];
		FOR(j,C[i]) cin>>I[i][j]>>P[i][j];
		FOR(j,C[i]) I[i][j]--;
	}
	
	FOR(i,1<<N) dpdp[i]=1e300;
	dpdp[(1<<N)-1]=0;
	
	for(int mask=(1<<N)-2;mask>=0;mask--) {
		FOR(i,M) {
			double t;
			int al=0;
			FOR(j,C[i]) if(mask & (1<<I[i][j])) al+=P[i][j];
			if(al==100) continue;
			t=cost[i]*100.0/(100-al);
			
			FOR(j,C[i]) {
				if(mask & (1<<I[i][j])) continue;
				t += P[i][j]/(100.0-al)*dpdp[mask | (1<<I[i][j])];
			}
			
			dpdp[mask] = min(dpdp[mask],t);
		}
	}
	_P("%.8f\n",dpdp[0]);
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


