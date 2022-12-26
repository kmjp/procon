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

vector<ll> enumpr(ll n) {
	vector<ll> V;
	//if(n==1) return vector<ll>(1,1);
	for(ll i=2;i*i<=n;i++) while(n%i==0) V.push_back(i),n/=i;
	if(n>1) V.push_back(n);
	sort(V.begin(),V.end());
	return V;
}


int N;
map<int,int> M;
const ll mo=1000000007;
ll ret;

ll from[3030],to[3030];

ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		auto V=enumpr(x);
		FORR(v,V) M[v]++;
	}
	ret=1;
	from[0]=2;
	FORR(m,M) {
		ret=ret*(m.second+1)%(mo-1);
		ZERO(to);
		FOR(i,3020) if(from[i]) {
			// no
			(to[i]+=from[i])%=mo;
			// add
			(to[i]+=from[i]*i%mo*m.second)%=mo;
			// new
			(to[i+1]+=from[i]*m.second)%=mo;
		}
		swap(from,to);
	}
	ret=modpow(2,ret);
	FOR(i,3030) ret-=from[i];
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
