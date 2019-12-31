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

ll tot(ll Y) {
	return (13+Y-2000)*(Y-2013+1)/2;
}

void solve() {
	int f,i,j,k,l,x,y,z;
	ll Y,M;
	cin>>Y>>M;
	M=(Y-2013)*12+M-1;
	
	ll L=2013,R=1LL<<31;
	FOR(i,60) {
		ll p=(L+R)/2;
		if(tot(p)<M) L=p;
		else R=p-1;
	}
	for(L=max(L-3,2013LL);L;L++) {
		if(M-tot(L-1)<L-2000) return _P("%lld %lld\n",L,M-tot(L-1)+1);
	}
}



int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


