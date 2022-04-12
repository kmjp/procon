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

ll dp[6030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	for(i=1;i<=M;i++) {
		dp[1][i]=1;
		dp[i][i]+=mo-1;
	}
	for(i=1;i<=N;i++) {
		ll sum=0;
		for(j=1;j<=M;j++) {
			(dp[i][j]+=dp[i-1][j])%=mo;
			sum+=dp[i][j];
		}
		sum%=mo;
		for(j=1;j<=M;j++) {
			ll add=(sum+mo-dp[i][j])%mo;
			(dp[i+1][j]+=add)%=mo;
			(dp[i+j][j]+=mo-add)%=mo;
		}
	}
	
	ll ret=1;
	FOR(i,N) ret=ret*M%mo;
	FOR(i,M) ret+=mo-dp[N][i+1];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
