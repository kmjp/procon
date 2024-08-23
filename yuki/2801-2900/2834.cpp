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

ll N,A,K;
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>K;
	ll g=__gcd(A,K);
	A/=g;
	K/=g;
	
	ll ret=0;
	FOR(j,K) {
		__int128 r=(N-j)/K;
		if(j>N) continue;
		r%=mo;
		ret+=K*(A%mo)%mo*((r*(r+1)*(2*r+1)/6)%mo);
		ret+=(A%mo)*j%mo*((r*(r+1)/2)%mo);
		ret+=((__int128)A*j/K*K%mo)*((r*(r+1)/2)%mo);
		ret+=((__int128)A*j/K%mo)*j%mo*(r+1)%mo;
		ret%=mo;
	}
	
	ll cur=0;
	FOR(i,2*K) {
		ll a=__int128(N-i)*A%K;
		if(a>cur) {
			a-=cur;
			cur=K-a;
			
			ll t=N-i;
			ll s=(N-i)%(2*K);
			(ret+=((__int128)(s+t)*((t-s)/(2*K)+1)/2)%mo)%=mo;
			
		}
		else {
			cur-=a;
		}
	}
	
	ret=ret*2%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
