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

int N,E[20][20];
int dpdp[20][1<<20];

int dfs(int cur,int mask) {
	int i;
	if(dpdp[cur][mask]>=0) return dpdp[cur][mask];
	if(mask==(1<<N)-1) {
		dpdp[cur][mask]=E[cur][0];
	}
	else {
		dpdp[cur][mask]=1<<30;
		FOR(i,N) if((mask & (1<<i))==0) {
			dpdp[cur][mask]=min(dpdp[cur][mask],E[cur][i]+dfs(i,mask | (1<<i)));
		}
	}
	return dpdp[cur][mask];
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) for(j=i+1;j<N;j++) {
		cin>>E[i][j];
		E[j][i]=E[i][j];
	}
	if(N==2) return _P("0 0\n");
	MINUS(dpdp);
	_P("%d %d\n",N,dfs(0,1));
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


