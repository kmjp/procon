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
int A[101];

int dp[55][50005];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N+1) FOR(j,50000+1) dp[i][j]=-1<<30;
	dp[0][0]=1<<30;
	FOR(i,N) FOR(j,50001) if(dp[i][j]>=0) {
		int tot=0;
		for(x=1;i+x<=N && x<N;x++) {
			tot+=A[i+x-1];
			dp[i+x][max(j,tot)]=max(dp[i+x][max(j,tot)], min(dp[i][j],tot));
		}
	}
	
	int ret=1<<30;
	FOR(j,50001) if(dp[N][j]>0 ) {
		ret=min(ret,j-dp[N][j]);
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
