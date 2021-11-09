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


int N,K;
int L[55],R[55];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dp[55][55];
ll re[155];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>L[i]>>R[i];
	for(i=1;i<=150;i++) re[i]=modpow(i);
	
	ll ret=0;
	for(x=0;x<100;x++) {
		ZERO(dp);
		dp[0][0]=1;
		FOR(y,N) {
			ll same=0,mor=0;
			if(L[y]<=x&&x<R[y]) {
				same=re[R[y]-L[y]];
				mor=(R[y]-x-1)*re[R[y]-L[y]]%mo;
			}
			else if(x<R[y]) {
				mor=1;
			}
			ll les=(1-same-mor+2*mo)%mo;
			for(j=y+2;j>=0;j--) for(k=y+2;k>=0;k--) if(dp[j][k]) {
				(dp[j][k+1]+=dp[j][k]*same)%=mo;
				(dp[j+1][k]+=dp[j][k]*mor)%=mo;
				(dp[j][k]=dp[j][k]*les)%=mo;
			}
		}
		FOR(j,N+1) FOR(k,N+1) if(j<K&&j+k>=K&&dp[j][k]) {
			int s=K-j;
			(ret+=dp[j][k]*(x+(k+1-s)*re[k+1]%mo)%mo)%=mo;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
