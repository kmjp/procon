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

const ll mo=1000000007;
ll A,B;
set<int> V[101010];

ll modpow(ll a, ll n = mo-2, ll m=mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%m,a=a*a%m,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	//cin>>A>>B;
	A=100;
	B=132;
	ll Y=modpow(A,B);
	for(i=100;i<=100000;i++) {
		ll k=__gcd((ll)i,Y);
		ll x=modpow(i,A,B);
		V[k].insert(x);
		//cout<<i<<" "<<k<<" "<<x<<endl;
	}
	//FOR(i,B) if(V[i].size()) cout<<i<<" "<<V[i].size()<<endl;
	
	cout<<A<<" "<<B<<endl;
	cin>>k;
	cout<<*V[k].begin()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
