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

ll H,W;
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll A[303030],B[303030],C[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	ll all=1LL*H*W%mo;
	ll ret=all*(all-1)%mo*(all-2)%mo*modpow(6)%mo;
	
	ret-=W*H%mo*(H-1)%mo*(H-2)%mo*modpow(6);
	ret-=H*W%mo*(W-1)%mo*(W-2)%mo*modpow(6);
	ret=(ret%mo+mo)%mo;
	
	for(i=1;i<W;i++) A[i]=(W-i)%mo;
	for(i=1;i<H;i++) B[i]=(H-i)%mo;
	
	for(i=1;i<=300000;i++) {
		ll SA=0;
		ll SB=0;
		for(x=i;x<=300000;x+=i) {
			SA+=A[x];
			SB+=B[x];
		}
		SA%=mo;
		SB%=mo;
		C[i]=2*SA*SB%mo;
	}
	for(i=300000;i>=1;i--) {
		for(x=2*i;x<=300000;x+=i) {
			C[i]-=C[x];
		}
		C[i]=(C[i]%mo+mo)%mo;
		ret-=(i-1)*C[i]%mo%mo;
	}
	cout<<(ret%mo+mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
