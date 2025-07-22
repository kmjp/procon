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

ll N,M;
ll A[303];
ll dp[92909];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<pair<ll,ll>> V;
	FOR(i,M) {
		cin>>x>>y;
		A[x]=max(A[x],(ll)y);
	}
	
	FOR(i,91505) dp[i]=-1LL<<60;
	
	for(i=1;i<=300;i++) {
		ll a=max(0LL,N-90000)/(i-A[i]);
		chmax(dp[N-a*(i-A[i])],i*a);
	}
	
	for(i=91000;i>=0;i--) if(dp[i]>=0) {
		for(j=1;j<=min(i,300);j++) chmax(dp[i-j+A[j]],dp[i]+j);
	}
	cout<<dp[0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
