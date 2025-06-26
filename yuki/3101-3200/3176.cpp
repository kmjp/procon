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

int T,N,K;


ll mo=998244353;
ll ma[202020][41],V[202020],R[202020];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			ma[i][K]=2*K;
			V[i]=2*K+1;
			for(j=-K;j<=K;j++) if(j&&i+j>=0&&i+j<N) ma[i][K+j]=mo-1;
		}
		
		FOR(i,N) {
			ll a=modpow(ma[i][K]);
			FOR(j,2*K+1) (ma[i][j]*=a)%=mo;
			(V[i]*=a)%=mo;
			for(j=1;j<=K;j++) if(i+j<N&&ma[i+j][K-j]) {
				ll v=mo-ma[i+j][K-j];
				FOR(k,K+1) (ma[i+j][K-j+k]+=v*ma[i][K+k])%=mo;
				(V[i+j]+=v*V[i])%=mo;
			}
		}
		for(i=N-1;i>=0;i--) {
			for(j=1;j<=K;j++) if(i-j>=0&&ma[i-j][K+j]) {
				(V[i-j]-=ma[i-j][K+j]*V[i])%=mo;
			}
		}
		FOR(i,N) cout<<(V[i]%mo+mo)%mo<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
