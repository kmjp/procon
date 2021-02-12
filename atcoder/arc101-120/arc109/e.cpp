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
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll ret[202020];
ll p2[202020],r2[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	p2[0]=r2[0]=1;
	FOR(i,201010) {
		p2[i+1]=p2[i]*2%mo;
		r2[i+1]=r2[i]*(mo+1)/2%mo;
	}
	
	for(i=2;i<=(N-1)/2;i++) {
		(ret[i]=ret[i-1]+2*(2*i-1)*r2[N-(2*i-3)])%=mo;
	}
	
	FOR(i,N) {
		j=N-1-i;
		ll dif=ret[min(i,j)];
		ll pat=(N+dif)*r2[1]%mo;
		cout<<pat<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
