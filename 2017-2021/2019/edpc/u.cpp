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
int A[16][16];
ll SA[1<<16];
ll dp[1<<16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>A[y][x];
	int mask;
	FOR(mask,1<<N) {
		FOR(x,N) FOR(y,x) if((mask&(1<<x))&&(mask&(1<<y))) SA[mask]+=A[x][y];
		dp[mask]=-1LL<<60;
	}
	dp[0]=0;
	FOR(mask,(1<<N)-1) {
		int first;
		FOR(first,N) if((mask&(1<<first))==0) break;
		int submask=((1<<N)-1)^mask^(1<<first);
		for(int sm2=submask; sm2>=0; sm2--) {
			sm2&=submask;
			
			dp[mask | sm2 | (1<<first)] = max(dp[mask | sm2 | (1<<first)], dp[mask] + SA[sm2 | (1<<first)]);
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
