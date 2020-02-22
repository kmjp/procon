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
ll X;
ll W[33];
map<ll,ll> MM[2];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>X;
	FOR(i,N) cin>>W[i];
	
	int mask;
	FOR(mask,1<<16) {
		ll tot=0;
		FOR(i,16) {
			if(mask&(1<<i)) {
				if(i>=N) {
					tot=-1;
					break;
				}
				tot+=W[i];
			}
		}
		if(tot>=0) MM[0][tot]++;
		tot=0;
		FOR(i,16) {
			if(mask&(1<<i)) {
				if(i+16>=N) {
					tot=-1;
					break;
				}
				tot+=W[i+16];
			}
		}
		if(tot>=0) MM[1][tot]++;
	}
	
	ll ret=0;
	ITR(it,MM[0]) ret += it->second * MM[1][X-it->first];
	_P("%lld\n",ret);
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


