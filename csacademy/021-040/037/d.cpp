#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;

int N,M;
int D[101010];
vector<int> E[101010];
vector<int> cand[101010];
int same[101010];
set<int> nei[101010];
int mad;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>D[i];
		cand[D[i]].push_back(i);
		mad=max(mad,D[i]);
	}
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		if(D[x]==D[y]) {
			same[x]++;
		}
		else {
			if(D[x]>D[y]) swap(x,y);
			
			if(D[x]+1==D[y]) nei[y].insert(x);
			else return _P("0\n");
		}
	}
	
	if(cand[0].size()!=1) return _P("0\n");
	
	ll ret=1;
	for(i=1;i<=mad;i++) {
		int tar=cand[i-1].size();
		// clo
		FORR(e,cand[i]) {
			int need=nei[e].size();
			
			if(need>0) {
				(ret *= modpow(2,tar-need))%=mo;
			}
			else {
				(ret *= modpow(2,tar)+mo-1)%=mo;
			}
		}
		// same;
		ll x=cand[i].size();
		ll ne=x*(x-1)/2;
		FORR(e,cand[i]) ne-=same[e];
		(ret *= modpow(2,ne))%=mo;
	}
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
