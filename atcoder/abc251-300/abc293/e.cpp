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

ll A,M,X;


ll totient(ll v) {
	ll ret=v;
	for(ll i=2;i*i<=v;i++) if(v%i==0) {
		ret=ret/i*(i-1);
		while(v%i==0) v/=i;
	}
	if(v>1) ret=ret/v*(v-1);
	return ret;
}

ll modpow(ll a, ll n, ll mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dfs(ll x) {
	if(x==1) return 1;
	if(x%2==1) return (1+A*dfs(x-1))%M;
	ll a=dfs(x/2);
	return a*(1+modpow(A,x/2,M))%M;
	
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>X>>M;
	
	cout<<dfs(X)%M<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
