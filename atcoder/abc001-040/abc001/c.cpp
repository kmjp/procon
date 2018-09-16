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



void solve() {
	int f,i,j,k,l, x,y;
	string S;
	cin>>x>>y;
	
	if(x<=112 || x>=3488) S="N";
	else if(x<=337) S="NNE";
	else if(x<=562) S="NE";
	else if(x<=787) S="ENE";
	else if(x<=1012) S="E";
	else if(x<=1237) S="ESE";
	else if(x<=1462) S="SE";
	else if(x<=1687) S="SSE";
	else if(x<=1912) S="S";
	else if(x<=2137) S="SSW";
	else if(x<=2362) S="SW";
	else if(x<=2587) S="WSW";
	else if(x<=2812) S="W";
	else if(x<=3037) S="WNW";
	else if(x<=3262) S="NW";
	else if(x<=3487) S="NNW";
	
	l=0;
	if(y>=2.5*6) l++;
	if(y>=15.5*6) l++;
	if(y>=33.5*6) l++;
	if(y>=54.5*6) l++;
	if(y>=79.5*6) l++;
	if(y>=107.5*6) l++;
	if(y>=138.5*6) l++;
	if(y>=171.5*6) l++;
	if(y>=207.5*6) l++;
	if(y>=244.5*6) l++;
	if(y>=284.5*6) l++;
	if(y>=326.5*6) l++;
	if(l==0) S="C";
	
	_P("%s %d\n",S.c_str(),l);
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


