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

int N,K;
int P[202020];
const ll mo=998244353;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll base=0;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
		base+=bt(N)-bt(P[i]);
		bt.add(P[i],1);
	}
	
	FOR(i,N) bt.add(i,-1);
	
	ll add=0;
	ll cur=0;
	FOR(i,K-1) {
		(cur+=bt(N)-bt(P[i])+mo)%=mo;
		bt.add(P[i],1);
	}
	for(i=K-1;i<N;i++) {
		(cur+=bt(N)-bt(P[i])+mo)%=mo;
		(add+=cur)%=mo;
		bt.add(P[i],1);
		(cur+=mo-bt(P[i-(K-1)]-1))%=mo;
		bt.add(P[i-(K-1)],-1);
	}
	add=add*modpow(N+1-K)%mo;
	base=base+mo-add+1LL*K*(K-1)%mo*modpow(4)%mo;
	cout<<base%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
