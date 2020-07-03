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
string S[202];
ll dp[1<<20];
ll mo=1000000007;
ll fact[21];
ll ret[21];
int cost[20][20];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	FOR(x,N) FOR(y,N) {
		cost[x][y]=1;
		while(cost[x][y]<=S[x].size() && cost[x][y]<=S[y].size() && S[x][cost[x][y]-1]==S[y][cost[x][y]-1]) cost[x][y]++;
	}
	
	fact[0]=1;
	FOR(i,N) fact[i+1]=fact[i]*(i+1)%mo;
	
	
	for(int mask=0;mask<1<<N;mask++) {
		int b=__builtin_popcount(mask);
		ret[b] += dp[mask];
		FOR(i,N) if((mask&(1<<i))==0) {
			int ma=1;
			FOR(x,N) if((mask&(1<<x))==0 && (i!=x)) ma=max(ma,cost[i][x]);
			(dp[mask|(1<<i)] += dp[mask]+ma*fact[b])%=mo;
		}
	}
	
	for(i=1;i<=N;i++) cout<<ret[i]%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
