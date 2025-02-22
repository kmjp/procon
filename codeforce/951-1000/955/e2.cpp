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
ll N,K;
const ll mo=1000000007;

map<ll,array<ll,4>> memo[66];

array<ll,4> hoge(ll R,int k) {  // L,R,all,sum
	if(R==0||k<0) return {0,0,0,0};
	if(R<=1LL<<k) return {0,0,R%mo,0};
	if(k==0) return {1,0,0,0};
	
	if(memo[k].count(R)) return memo[k][R];
	
	ll M=1;
	while(M*2<R) M*=2;
	auto a=hoge(M,k);
	auto b=hoge(R-M,k-1);
	array<ll,4> c={0,0,0,0};
	if(a[2]&&b[2]) {
		c[2]=a[2]+b[2];
	}
	else if(a[2]) {
		c[0]=a[2]+b[0];
		c[1]=b[1];
		c[3]=b[3];
	}
	else if(b[2]) {
		c[0]=a[0];
		c[1]=a[1]+b[2];
		c[3]=a[3];
	}
	else {
		c[0]=a[0];
		c[1]=b[1];
		ll v=(a[1]+b[0])%mo;
		c[3]=a[3]+b[3]+v*(v+1)/2;
	}
	
	
	c[0]%=mo;
	c[1]%=mo;
	c[2]%=mo;
	c[3]%=mo;
	memo[k][R]=c;
	return c;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		auto a=hoge(N,K);
		a[3]+=a[0]*(a[0]+1)/2;
		a[3]+=a[1]*(a[1]+1)/2;
		a[3]+=a[2]*(a[2]+1)/2;
		cout<<a[3]%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
