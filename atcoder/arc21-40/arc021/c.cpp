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

ll K,N;
ll A[100001],D[100001];

ll numnum(ll po) {
	ll ret=0;
	int i;
	FOR(i,N) if(po>=A[i]) ret+=1+(po-A[i])/D[i];
	return ret;
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>K>>N;
	FOR(i,N) cin>>A[i]>>D[i];
	
	ll LL=1,RR=1LL<<40;
	FOR(i,100) {
		ll po=(LL+RR)/2;
		if(numnum(po)>=K) RR=po;
		else LL=po;
	}
	
	while(numnum(LL)<K) LL++;
	while(numnum(LL)>K) LL--;
	ll tot=(LL+1)*(K-numnum(LL));
	
	FOR(i,N) {
		if(LL<A[i]) continue;
		ll nu=1+(LL-A[i])/D[i];
		tot+=nu*A[i] + D[i]*(nu*(nu-1)/2);
	}
	
	_P("%lld\n",tot);
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


