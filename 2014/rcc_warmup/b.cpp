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
ll B;
ll X[201],K[201];
int MA[201];
vector<ll> KK;
ll dpdp[2][1<<20];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M>>B;
	vector<pair<int,int> > VV;
	FOR(i,N) {
		cin>>X[i]>>K[i]>>k;
		VV.push_back(make_pair(K[i],i));
		FOR(x,k) cin>>y, MA[i] |= 1<<(y-1);
	}
	
	sort(VV.begin(),VV.end());
	
	ll mi=1LL<<62;
	FOR(x,1<<M) dpdp[0][x]=dpdp[1][x]=1LL<<62;
	dpdp[0][0]=dpdp[1][0]=0;
	
	FOR(i,N) {
		FOR(x,1<<M) dpdp[1][x|MA[VV[i].second]] = min(dpdp[1][x|MA[VV[i].second]],dpdp[0][x]+X[VV[i].second]);
		mi=min(mi,dpdp[1][(1<<M)-1]+VV[i].first*B);
		memmove(dpdp[0],dpdp[1],sizeof(dpdp[0]));
	}
	if(mi>=1LL<<62) _P("-1\n");
	else cout << mi << endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


