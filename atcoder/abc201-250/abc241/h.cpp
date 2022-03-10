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
ll M,A[16],B[16],C[16];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i]>>B[i];
	
	FOR(i,N) {
		C[i]=1;
		FOR(j,N) if(j!=i) (C[i]*=(mo+1-A[j]*modpow(A[i])%mo))%=mo;
		C[i]=modpow(C[i]);
	}
	int mask;
	ll ret=0;
	FOR(mask,1<<N) {
		ll p=1,q=0;
		FOR(i,N) if(mask&(1<<i)) {
			p=(mo-p)*modpow(A[i],B[i]+1)%mo;
			q+=B[i]+1;
		}
		if(q<=M) {
			FOR(i,N) (ret+=C[i]*p%mo*modpow(A[i],M-q))%=mo;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
