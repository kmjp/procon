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
int A;
ll dp[1<<16][16];
int T[16][16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	
	FOR(i,K) {
		cin>>x;
		A|=1<<(x-1);
	}
	FOR(y,N) FOR(x,N) cin>>T[y][x];
	
	int mask;
	FOR(mask,1<<N) FOR(i,N) dp[mask][i]=1LL<<60;
	FOR(i,N) dp[1<<i][i]=0;
	FOR(mask,1<<N) FOR(i,N) if(mask&(1<<i)) {
		FOR(j,N) if((mask&(1<<j))==0) chmin(dp[mask|(1<<j)][j],dp[mask][i]+T[i][j]);
	}
	ll ret=1LL<<60;
	FOR(mask,1<<N) if(__builtin_popcount(mask)>=M) FOR(i,N) if(A&(1<<i)) {
		ret=min(ret,dp[mask][i]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
