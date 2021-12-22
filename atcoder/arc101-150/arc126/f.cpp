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
int X[1010];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

bool comp(pair<ll,ll> A,pair<ll,ll> B) {
	return A.first*B.second<A.second*B.first;
}

int ok(ll p,ll q) {
	ll a[1010];
	int i;
	FOR(i,N+1) {
		a[i]=(X[i]*p)%q;
	}
	ll ret=0;
	FOR(i,N) {
		if(a[i]==a[i+1]) return 0;
		if(a[i]<a[i+1]) ret+=a[i+1]-a[i];
		else ret+=q+a[i+1]-a[i];
	}
	return ret==q;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i];
	X[N]=X[0];
	vector<pair<ll,ll>> C;
	C.push_back({0,1});
	C.push_back({1,1});
	FOR(i,N) {
		x=abs(X[i]-X[i+1]);
		for(j=1;j<x;j++) {
			k=__gcd(j,x);
			C.push_back({j/k,x/k});
		}
	}
	sort(ALL(C),comp);
	C.erase(unique(ALL(C)),C.end());
	ll ret=0;
	FOR(i,C.size()-1) {
		ll p=C[i].first*C[i+1].second+C[i].second*C[i+1].first;
		ll q=C[i].second*C[i+1].second*2;
		if(ok(p,q)) {
			ll L=C[i].first*modpow(C[i].second)%mo;
			ll R=C[i+1].first*modpow(C[i+1].second)%mo;
			if(X[N-1]>X[0]) {
				ll e=X[N-1]*p-X[0]*p;
				ll f=e/q+1;
				ret+=f*(R-L);
				ret+=-(X[N-1]-X[0])*(R*R%mo-L*L%mo)%mo*modpow(2);
			}
			else {
				ll e=X[0]*p-X[N-1]*p;
				ll f=e/q;
				ret+=-f*(R-L);
				ret+=-(X[N-1]-X[0])*(R*R%mo-L*L%mo)%mo*modpow(2);
			}
			ret=ret%mo;
		}
	}
	cout<<(ret%mo+mo)%mo*modpow(3)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
