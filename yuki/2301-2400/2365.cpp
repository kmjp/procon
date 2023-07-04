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
ll K;
const ll mo=1000000007;

int d[101010];

ll modpow(ll a, ll n,ll mo=1000000007) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=100001;i++) {
		if(d[i]==0) {
			for(j=i;j<=100001;j+=i) d[j]=i;
		}
	}
	
	cin>>N>>K;
	map<ll,ll> M;
	while(N>1) {
		M[d[N]]++;
		N/=d[N];
	}
	
	FOR(i,200100) if(K) {
		if(i>200000&&K%2==0) continue;
		K--;
		map<ll,ll> M2;
		FORR2(a2,b,M) {
			ll a=a2+1;
			while(a>1) {
				(M2[d[a]]+=b)%=mo-1;
				a/=d[a];
			}
		}
		swap(M,M2);
	}
	
	
	ll ret=1;
	K/=2;
	FORR2(a,b,M) {
		assert(K==0||a<=3);
		b=b*modpow(2,K,mo-1)%(mo-1);
		ret=ret*modpow(a,b)%mo;
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
