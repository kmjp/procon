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
ll A[101010];
const ll mo=998244353;
ll dp[101010][2][2];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll C2(ll a) {
	return a*(a-1)%mo*modpow(2)%mo;
}
ll C3(ll a) {
	return a*(a-1)%mo*(a-2)%mo*modpow(6)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	ll ret=0;
	FOR(x,2) {
		ZERO(dp);
		dp[0][x][0]=1;
		FOR(i,N) {
			ll P=A[i];
			
			FOR(k,2) {
				// move 0
				(dp[i+1][0][1]+=P*dp[i][0][k])%=mo;
				(dp[i+1][0][1]+=dp[i][1][k])%=mo;
				// move > 0
				(dp[i+1][0][k]+=C2(P)*dp[i][0][k])%=mo;
				(dp[i+1][0][k]+=P*dp[i][1][k])%=mo;
				(dp[i+1][1][k]+=C3(P+1)*dp[i][0][k])%=mo;
				(dp[i+1][1][k]+=(P+C2(P))*dp[i][1][k])%=mo;
			}
		}	
		ret+=dp[N][x][1];
	}
	
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
