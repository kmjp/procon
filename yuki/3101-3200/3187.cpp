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

ll N;
ll mo;

ll dp[603030];
vector<int> D[606060];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	for(i=1;i<=N;i++) {
		for(j=i;j<=N;j+=i) D[j].push_back(i);
	}
	
	for(i=3;i<=N;i++) {
		(dp[i+1]+=dp[i])%=mo;
		dp[i]=(i*modpow(i-D[i].size())%mo+dp[i]%mo*modpow(i-D[i].size()))%mo;
		FORR(d,D[i]) if(d>1) {
			(dp[i+1]+=dp[i])%=mo;
			(dp[i+d]+=mo-dp[i])%=mo;
		}
	}
	cout<<dp[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
