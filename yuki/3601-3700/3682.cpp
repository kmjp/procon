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

int T;
ll H1,A1,S1,H2,A2,S2;
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(ll a, ll b) {
	if(a<=0) return 0;
	if(b<=0) return 1;
	ll ret;
	if(min(a,b)>=2) {
		ret=hoge(a-(min(a,b)-1),b-(min(a,b)-1));
	}
	else if(a>=2) {
		ret =modpow(modpow(10),a-1)*hoge(1,1)+(1-modpow(modpow(10),a-1)+mo);
	}
	else if(b>=2) {
		ret =modpow(modpow(10),b-1)*hoge(1,1);
	}
	else {
		ret=10*modpow(11);
	}
	return (ret%mo+mo)%mo;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H1>>A1>>S1>>H2>>A2>>S2;
		H1=(H1+A2-1)/A2;
		H2=(H2+A1-1)/A1;
		
		ll a=hoge(H1,H2);
		ll b=hoge(H2,H1);
		if(S1>S2) cout<<a<<endl;
		else if(S1<S2) cout<<(1-b+mo)%mo<<endl;
		else cout<<(a+1-b+mo)*modpow(2)%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
