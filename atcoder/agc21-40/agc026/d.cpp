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
int H[105];
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

pair<ll,ll> hoge(int L,int R,int v) {
	ll dp1=1,dp2=1;
	int i;
	
	if(L>R) return {-1,1};
	
	int mi=1<<30;
	for(i=L;i<=R;i++) mi=min(mi,H[i]);
	int W=R-L+1;
	for(i=L;i<=R;i++) if(mi!=H[i]) W--;
	
	int pre=L-1;
	for(i=L;i<=R;i++) {
		if(mi==H[i]) {
			auto r=hoge(pre+1,i-1,mi);
			if(r.first>=0) {
				(dp1*=r.first)%=mo;
				(dp2*=r.first+r.second)%=mo;
			}
			
			pre=i;
		}
	}
	auto r=hoge(pre+1,R,mi);
	if(r.first>=0) {
		(dp1*=r.first)%=mo;
		(dp2*=r.first+r.second)%=mo;
	}
	
	(dp2=dp2*modpow(2,W)+(modpow(2,mi-v)+mo-2)*dp1)%=mo;
	(dp1*=modpow(2,mi-v))%=mo;
	
	return {dp1,dp2};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) cin>>H[i];
	cout<<hoge(1,N,0).second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
