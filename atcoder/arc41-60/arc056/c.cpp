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

int N,K;
int W[20][20];
ll dp[1<<20];
ll msum[1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(y,N) FOR(x,N) cin>>W[y][x];
	FOR(i,1<<N) FOR(y,N) FOR(x,y) if((i&(1<<x))&&(i&(1<<y))) msum[i]+=W[y][x];
	
	for(int mask=1;mask<1<<N;mask++) {
		dp[mask]=K;
		for(int i=(i-1)&mask; i>0; i=(i-1)&mask) {
			int mask2=mask ^ i;
			dp[mask] = max(dp[mask],dp[i]+dp[mask2]-msum[mask]+msum[i]+msum[mask2]);
		}
	}
	
	cout<<dp[(1<<N)-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
