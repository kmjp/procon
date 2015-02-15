#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,K;
char S[100005];

ll mo[2]={1000000007,1000000009};
ll prime[]={10007,10009,10037,10039,10061,10067,10069,10079,10091,10093,10099,10103,10111,10133,10139,10141,10151,
10159,10163,10169,10177,10181,10193,10211,10223,10243,10247,10253,10259};
ll rev[2][26];

int SS[26][100005];

ll modpow(ll a, ll n, ll mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

map<pair<ll,ll>,vector<int> > MM;

void solve() {
	int f,i,j,k,l,x,y;
	
	FOR(i,26) rev[0][i]=modpow(prime[i],mo[0]-2,mo[0]);
	FOR(i,26) rev[1][i]=modpow(prime[i],mo[1]-2,mo[1]);
	
	cin>>N>>K>>S;
	if(K*2>N) return _P("NO\n");
	
	FOR(i,26) FOR(x,N) SS[i][x+1]=SS[i][x]+(S[x]=='a'+i);
	
	ll hash[2]={1,1};
	FOR(i,N) {
		hash[0]=hash[0]*prime[S[i]-'a']%mo[0];
		hash[1]=hash[1]*prime[S[i]-'a']%mo[1];
		if(i>=K) {
			hash[0]=hash[0]*rev[0][S[i-K]-'a']%mo[0];
			hash[1]=hash[1]*rev[1][S[i-K]-'a']%mo[1];
		}
		if(i>=K-1) MM[make_pair(hash[0],hash[1])].push_back(i-(K-1));
	}
	
	ITR(it,MM) {
		vector<int> VV=it->second;
		FOR(x,VV.size()) for(y=x+1;y<VV.size();y++) {
			if(VV[y]<VV[x]+K) continue;
			int ng=0;
			FOR(i,26) {
				if(SS[i][VV[x]+K]-SS[i][VV[x]]!=SS[i][VV[y]+K]-SS[i][VV[y]]) ng++;
			}
			if(ng==0) return _P("YES\n");
		}
	}
	return _P("NO\n");
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


