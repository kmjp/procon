#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
ll A[202020];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dp[202020];

void solve() {
	int i,j,k,l,r,x,y; 
	
	cin>>N;
	vector<pair<ll,int>> V;
	FOR(i,N) {
		cin>>A[i];
		if(V.empty()||V.back().first!=A[i]) V.push_back({A[i],0});
		V.back().second++;
	}
	reverse(ALL(V));
	
	int ok=N;
	ll penalty=0;
	ll ret=0;
	int s=0;
	FOR(i,V.size()-1) {
		ok-=V[i].second;
		ll turn=V[i].first-V[i+1].first;
		ll okp=ok*modpow(N)%mo;
		// sum((i+1)*ok^i)
		ll a=(1-modpow(okp,turn)+mo)*modpow(1-okp+mo)%mo+mo-turn*modpow(okp,turn)%mo+mo;
		a=a%mo*modpow(1-okp+mo)%mo;
		// sum(ok^i)
		ll b=(1-modpow(okp,turn)+mo)*modpow(1-okp+mo)%mo;
		
		(a*=(1-okp+mo))%=mo;
		(b*=(1-okp+mo))%=mo;
		ll C=turn*modpow(okp,turn)%mo;
		C+=a;
		C+=penalty*b%mo*modpow(N-ok)%mo;
		C=C%mo;
		dp[i]=C*modpow(1-b+mo)%mo;
		
		(penalty+=(s+V[i].second)*dp[i])%=mo;
		s+=V[i].second;
		ret+=dp[i];
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
