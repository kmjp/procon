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
ll M;
ll D[17];
ll G[1<<16];
ll H[17];
const ll mo=998244353;
ll dp[1<<16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>D[i];
	int mask;
	FOR(mask,1<<N) if(mask) {
		ll lcm=1;
		FOR(i,N) if(mask&(1<<i)) {
			ll a=D[i]/__gcd(D[i],lcm);
			if(M/a<lcm) {
				lcm=M+1;
				break;
			}
			lcm*=a;
		}
		G[mask]=(M/lcm)%mo;
	}
	
	
	H[1]=1;
	for(i=2;i<=N;i++) H[i]=mo-((i-1)*H[i-1])%mo;
	
	dp[0]=1;
	for(mask=1;mask<1<<N;mask++) {
		FOR(i,N) if(mask&(1<<i)) break;
		int sm=mask^(1<<i);
		for(int mask2=sm;mask2>=0;--mask2) {
			mask2&=sm;
			int mask3=mask2^(1<<i);
			(dp[mask]+=G[mask3]*H[__builtin_popcount(mask3)]%mo*dp[mask^mask3])%=mo;
		}
	}
	cout<<dp[(1<<N)-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
