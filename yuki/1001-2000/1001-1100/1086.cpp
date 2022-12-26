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


int N;
ll L[101010],R[101010];
ll D;
const ll mo=1000000007;
ll dp[101010][10];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i];
	FOR(i,N) cin>>R[i];
	dp[0][0]=1;
	FOR(i,N) {
		cin>>D;
		ll num=(modpow(10,R[i])-modpow(10,L[i])+mo)*modpow(9)%mo;
		FOR(x,10) {
			FOR(y,10) {
				int z=x+y;
				if(z>9) z-=9;
				if(z!=D) continue;
				if(y==0) (dp[i+1][z]+=dp[i][x])%=mo;
				else (dp[i+1][z]+=num*dp[i][x])%=mo;
			}
		}
	}
	ll ret=0;
	FOR(i,10) ret+=dp[N][i];
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
