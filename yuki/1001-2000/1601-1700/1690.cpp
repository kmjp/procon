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

int N,M,K;
ll dp[18][18];
int A[18];
ll dp2[1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>A[i];
	
	FOR(x,N) FOR(y,N) dp[x][y]=(x==y)?0:(1LL<<60);
	FOR(i,M) {
		cin>>x>>y>>k;
		dp[x-1][y-1]=dp[y-1][x-1]=k;
	}
	FOR(k,N) FOR(x,N) FOR(y,N) dp[x][y]=min(dp[x][y],dp[x][k]+dp[k][y]);
	
	FOR(i,1<<N) dp2[i]=1LL<<60;
	FOR(i,N) dp2[1<<i]=A[i];
	int mask;
	ll ret=1LL<<60;
	FOR(mask,1<<N) if(mask) {
		FOR(x,N) if((mask&(1<<x))==0) {
			ll mi=1LL<<60;
			FOR(y,N) if(mask&(1<<y)) mi=min(mi,dp[x][y]);
			dp2[mask|(1<<x)]=min(dp2[mask|(1<<x)],dp2[mask]+A[x]+mi);
		}
		if(__builtin_popcount(mask)==K) ret=min(ret,dp2[mask]);
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
