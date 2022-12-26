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
int A[18],B[18];
int D[18][18];

int dp[1<<18][18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i]>>B[i];
	FOR(x,N) FOR(y,N) D[x][y]=B[x]-A[x]+A[y];
	
	int mask;
	FOR(mask,1<<N) FOR(i,N) dp[mask][i]=101010;
	FOR(i,N) dp[1<<i][i]=0;
	
	int ret=101010;
	for(int mask=0;mask<1<<N;mask++) {
		FOR(i,N) {
			if(mask==(1<<N)-1) ret=min(ret,dp[mask][i]);
			FOR(j,N) if((mask&(1<<j))==0) dp[mask^(1<<j)][j]=min(dp[mask^(1<<j)][j],max(dp[mask][i],D[i][j]));
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
