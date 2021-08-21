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
int C[10];
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2, ll mo=mo) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,9) {
		cin>>C[i+1];
		if(C[i+1]==N) {
			ll v=(modpow(10,N)+mo-1)*modpow(9)*(i+1)%mo;
			cout<<v<<endl;
			return;
		}
	}
	int g=0;
	FOR(x,9) FOR(y,x) if(C[x+1]&&C[y+1]) g=__gcd(g,x-y);
	
	ll v=0;
	FOR(i,9) {
		ll a=(modpow(10,C[i+1],81*g)-1)*(i+1)%(81*g);
		v=(v*modpow(10,C[i+1],81*g)+a)%(81*g);
	}
	v=__gcd(v,81LL*g);
	cout<<v/9<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
