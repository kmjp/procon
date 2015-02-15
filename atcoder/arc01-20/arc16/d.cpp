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

int N,M,H;
vector<int> E[101];
int D[101];
double dpdp[101][101];

int okok(double rc) {
	ZERO(dpdp);
	int f,i,j,k,l, x,y;
	
	for(i=N-2;i>=0;i--) for(j=1;j<=H;j++) {
		int ng=0;
		FOR(x,E[i].size()) if(D[E[i][x]]>=j) ng++;
		if(ng || E[i].empty()) {
			dpdp[i][j]=(H-j)+rc;
			continue;
		}
		dpdp[i][j] = 1;
		FOR(x,E[i].size()) dpdp[i][j] += dpdp[E[i][x]][j-D[E[i][x]]]/E[i].size();
		dpdp[i][j] = min(dpdp[i][j], (H-j)+rc);
	}
	return dpdp[0][H]<rc;
}

void solve() {
	int f,i,j,k,l, x,y;
	
	cin>>N>>M>>H;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
	}
	FOR(i,N) cin>>D[i];
	
	double lo=0,hi=1e9;
	FOR(i,60) {
		double mi=(lo+hi)/2;
		if(okok(mi)) hi=mi;
		else lo=mi;
	}
	if(lo>=1e8) _P("-1\n");
	else _P("%.8lf\n",lo);
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


