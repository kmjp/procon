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

int N,M,X;
const ll mo=998244353;

ll F[100];
int dp[1010][55001];
ll ret[55555];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	F[0]=F[1]=1;
	for(i=2;i<=30;i++) {
		F[i]=F[i-1]+F[i-2];
	}
	
	cin>>N>>X>>M;
	dp[0][0]=1;
	FOR(i,X-1) {
		FOR(x,N) FOR(y,F[i]*(x+1)) if(y+F[i]<=34000) (dp[x+1][y+F[i]]+=dp[x][y])%=mo;
	}
	FOR(x,N+1) FOR(y,F[X-1]*N+1) if(dp[x][y]) {
		(ret[y+F[X-1]*(N-x)]+=dp[x][y])%=mo;
	}
	
	
	
	ll pat=0;
	int mask;
	FOR(mask,1<<24) {
		if(__builtin_popcount(mask)!=M) continue;
		if(mask&1) continue;
		if(mask&(mask<<1)) continue;
		ll sum=0;
		FOR(i,24) if(mask&(1<<i)) sum+=F[i];
		(pat+=ret[sum])%=mo;
	}
	cout<<pat%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
