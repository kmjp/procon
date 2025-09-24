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

int N,M;
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll ret=0;
	for(i=1;i<=N;i++) {
		ll allpat=modpow(1LL*N*(N+1)/2,M);
		ret+=1LL*i*i%mo*allpat%mo;
	}
	
	ll p2=(mo+1)/2;
	for(i=1;i<=N;i++) {
		int P;
		cin>>P;
		//iÇä™Ç´çûÇ‹Ç»Ç¢ämó¶
		ll move=(1LL*i*(N+1-i))%mo;
		ll stay=(1LL*N*(N+1)/2-move+mo)%mo;
		ll allstay=modpow(stay,M);
		ll onemove=(modpow(1LL*N*(N+1)/2,M)-allstay)%mo;
		ret+=allstay*i%mo*(mo-P)%mo;
		ret+=onemove*(N+1)%mo*p2%mo*(mo-P)%mo;
	}
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
