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

int N,M;
ll A[1010];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll L=1;
	FOR(i,N) {
		cin>>A[i];
		L=L*A[i]/__gcd(L,A[i]);
	}
	ll ret=0;
	vector<pair<ll,ll>> C;
	for(i=1;i*i<=L;i++) if(L%i==0) {
		C.push_back({i,0});
		if(i*i!=L) C.push_back({L/i,0});
	}
	sort(ALL(C));
	FORR2(g,v,C) {
		v=1;
		FOR(i,N) {
			x=__gcd(g,(ll)A[i]);
			(v*=modpow(M,x))%=mo;
		}
		FORR2(g2,v2,C) if(g2<g&&g%g2==0) v+=mo-v2;
		v%=mo;
		ret+=v*modpow(g)%mo;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
