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
void _fill_ll(ll* p,ll val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

void solve() {
	int f,i,j,k,l, x,y;
	string S;
	
	cin>>S;
	FOR(i,S.size()) {
		if(S[i]=='a') continue;
		if(S[i]=='i') continue;
		if(S[i]=='u') continue;
		if(S[i]=='e') continue;
		if(S[i]=='o') continue;
		_P("%c",S[i]);
	}
	_P("\n");
	
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


