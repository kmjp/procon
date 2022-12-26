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

ll L,R;

ll numprime(ll N) {
	if(N<=3) return max(0LL,N-1);
	ll sq=sqrt(N)+1;
	static vector<ll> small, large;
	small.resize(1+sq,0);
	large.resize(1+sq,0);
	ll i,j,p;
	for(i=1;i<=sq;i++) large[i]=N/i-1, small[i]=i-1;
	for(p=2;p<=sq;p++) {
		if(small[p]<=small[p-1]) continue;
		ll pc=small[p-1];
		ll q=p*p;
		for(i=1;i<=sq&&N/i>=q;i++) {
			ll ip=1LL*i*p;
			ll cur=(ip<=sq?large[ip]:small[N/ip])-pc;
			(i<=sq?large[i]:small[N/i])-=cur;
		}
		for(i=sq;i>=q;i--) small[i]-=small[i/p]-pc;
	}
	return large[1];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>R;
	
	ll ret=numprime(R)-numprime(L-1)+numprime(2*R)-numprime(2*L);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
