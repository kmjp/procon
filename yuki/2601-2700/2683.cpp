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

ll H,W,A,B;

const ll mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>A>>B;
	
	vector<ll> F(A+1),G(B+1);
	ll a=(H-A+1)*(W-B+1)%mo;

	ll add=0;
	for(i=1;i<=A;i++) {
		int w=2*A-i;
		if(w>H) continue;
		if(i==A) (add+=(H+1-w)*i)%=mo;
		else (add+=2LL*(H+1-w)*i)%=mo;
	}
	ll pat=0;
	for(i=1;i<=B;i++) {
		int w=2*B-i;
		if(w>W) continue;
		if(i==B) (pat+=1LL*(W+1-w)*i%mo*add)%=mo;
		else (pat+=2LL*(W+1-w)*i%mo*add)%=mo;
	}
	pat=pat*modpow(a*a)%mo;
	ll ret=2*A*B%mo+mo-pat;
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
