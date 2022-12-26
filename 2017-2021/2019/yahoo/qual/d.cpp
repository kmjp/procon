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
int A[202020];
ll S[202020];
ll L[202020][3];
ll R[202020];
ll dp[202020][5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	dp[0][1]=dp[0][2]=dp[0][3]=dp[0][4]=1LL<<60;
	FOR(i,N) {
		cin>>A[i];
		dp[i+1][0]=dp[i][0]+A[i];
		dp[i+1][1]=min({dp[i][0],dp[i][1]})+((A[i]==0)?2:A[i]%2);
		dp[i+1][2]=min({dp[i][0],dp[i][1],dp[i][2]})+(1-A[i]%2);
		dp[i+1][3]=min({dp[i][0],dp[i][1],dp[i][2],dp[i][3]})+((A[i]==0)?2:A[i]%2);
		dp[i+1][4]=min({dp[i][0],dp[i][1],dp[i][2],dp[i][3],dp[i][4]})+A[i];
	}
	cout<<min({dp[N][0],dp[N][1],dp[N][2],dp[N][3],dp[N][4]})<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
