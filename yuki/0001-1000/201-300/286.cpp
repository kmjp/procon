#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int M[20];
int dp[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>M[i];
	FOR(i,1<<N) dp[i]=1<<20;
	
	dp[0]=0;
	for(int mask=0;mask<(1<<N)-1;mask++) {
		int tot=0;
		FOR(i,N) if(mask&(1<<i)) tot+=M[i];
		tot %= 1000;
		FOR(i,N) if((mask&(1<<i))==0) dp[mask | (1<<i)] = min(dp[mask | (1<<i)],dp[mask]+max(0,M[i]-tot));
	}
	cout<<dp[(1<<N)-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
