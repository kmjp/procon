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
ll T[303030],V[303030];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll S=0;
	FOR(i,N) {
		cin>>T[i]>>V[i];
		T[i]%=mo;
		(S+=T[i])%=mo;
	}
	ll L=0;
	ll R=S;
	ll ret=0;
	FOR(i,N) {
		R=(R+mo-T[i])%mo;
		
		ll M=T[i];
		ll k1=M*(M+1)%mo*modpow(2)%mo;
		ll k2=M*(M+1)%mo*(2*M+1)%mo*modpow(6)%mo;
		ll k3=k1*k1%mo;
		
		ll a=L*(L+1)%mo*M%mo;
		a+=k1*(2*L+1)%mo;
		a+=k2%mo;
		a=a*(R+M+1)%mo;
		a-=k1*(L*(L+1)%mo)%mo;
		a-=k2*(2*L+1)%mo;
		a-=k3;
		
		a=(a*modpow(2)%mo+mo)%mo;
		(ret+=V[i]*a%mo)%=mo;
		(L+=T[i])%=mo;
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
