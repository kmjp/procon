#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	ll g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}


pair<ll,ll> crt(ll a1,ll mo1,ll a2,ll mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	ll g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<ll,ll>(-1,0); // N/A
	__int128_t lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<ll,ll>(-2,0); // overflow
	
	__int128_t v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

int N,M;
int X[6];
int dp[10100000];
vector<int> P={168647939,592951213};
vector<pair<ll,ll>> C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	N--;
	FOR(i,M) cin>>X[i];
	FORR(p,P) {
		dp[0]=1;
		for(i=1;i<=(N+1)/2;i++) {
			ll tmp=0;
			FOR(j,M) if(i>=X[j]) tmp+=dp[i-X[j]];
			dp[i]=tmp%p;
		}
		ll ret=0;
		for(i=0;i<=(N+1)/2;i++) FOR(j,M) if(i+X[j]>(N+1)/2 && i+X[j]<=N) (ret+=1LL*dp[i]*dp[N-(i+X[j])])%=p;
		
		C.push_back({ret,p});
	}
	
	auto ret=crt(C[0].first,C[0].second,C[1].first,C[1].second);
	cout<<ret.first<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
