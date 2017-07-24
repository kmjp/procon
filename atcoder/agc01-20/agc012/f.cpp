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

int N,L;
int A[101];
map<int,int> M;
ll dp[110][110][110];
ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N-1) cin>>A[i+1];
	sort(A+1,A+2*N);
	
	dp[N][1][1]=1;
	for(i=N;i>=2;i--) {
		FOR(j,2*N+1) FOR(k,2*N+1) {
			ll cur=dp[i][j][k];
			if(cur==0) continue;
			
			int left=(A[i]!=A[i-1]);
			int right=(A[2*N-i]!=A[2*N-i+1]);
			
			// same
			(dp[i-1][j+left+right][k+left] += cur)%=mo;
			// left
			for(x=0;x<=k+left-2;x++) (dp[i-1][j+left+right-x][k-1+left-x] += cur)%=mo;
			
			// right
			for(x=k+left+1;x<=j+left+right;x++) (dp[i-1][x][k+left+1] += cur)%=mo;
		}
	}
	ll ret=0;
	FOR(j,2*N+1) FOR(k,2*N+1) ret+=dp[1][j][k];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
