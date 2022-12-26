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

int N;
ll L,H;
ll C[101];
ll dp[1<<10];
pair<ll,ll> P[1<<10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>H;
	FOR(i,N) cin>>C[i];
	
	for(int mask=0;mask<1<<N;mask++) {
		ll h = 1;
		FOR(i,N) if(mask&(1<<i)) {
			h*=C[i]/__gcd(h,C[i]);
			if(h>1LL<<30) break;
		}
		P[mask]=make_pair(h,__builtin_popcount(mask));
	}
	sort(P,P+(1<<N));
	
	ll ret=0;
	for(int mask=(1<<N)-1;mask>=0;mask--) {
		dp[mask]=H/P[mask].first-(L-1)/P[mask].first;
		for(int mask2=mask+1;mask2<(1<<N);mask2++) {
			if(P[mask2].first % P[mask].first == 0) {
				dp[mask] -= dp[mask2];
			}
		}
		if(P[mask].second==1) ret+=dp[mask];
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
