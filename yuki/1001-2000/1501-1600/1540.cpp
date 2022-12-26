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
ll A[101010];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll I[3][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	I[2][0]=modpow(6);
	I[0][1]=1;
	I[1][1]=mo-modpow(2);
	for(i=2;i<=N+2;i++) {
		I[0][i]=I[0][i-2]*(i-1)%mo*modpow(i)%mo;
		I[1][i]=I[1][i-2]*(i-1)%mo*modpow(i)%mo;
		I[2][i]=I[2][i-2]*(i-1)%mo*modpow(i)%mo;
		(I[1][i]+=mo-modpow(i*modpow(2,i)%mo))%=mo;
	}
	
	ll ret[3]={};
	FOR(i,N) {
		ll p=A[i]*modpow(2,i+1)%mo;
		(ret[0]+=p*I[0][i])%=mo;
		(ret[1]+=p*I[1][i])%=mo;
		(ret[2]+=p*I[2][i])%=mo;
	}
	cout<<ret[0]<<" "<<ret[1]<<" "<<ret[2]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
