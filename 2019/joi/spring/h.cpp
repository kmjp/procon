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
string A,B;
int dp[1010101][5];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	A="0"+A;
	B="0"+B;
	FOR(i,N+1) FOR(j,5) dp[i][j]=1<<30;
	dp[0][0]=0;
	for(i=1;i<=N;i++) {
		int pq=A[i-1]!=B[i-1];
		int p0='0'!=B[i-1];
		int p1='1'!=B[i-1];
		int cq=A[i]!=B[i];
		int c0='0'!=B[i];
		int c1='1'!=B[i];
		// ?->?
		dp[i][0]=min(dp[i][0],dp[i-1][0]+(pq==0&&cq));
		// ?->0
		dp[i][2]=min(dp[i][2],dp[i-1][0]+1+(pq==0&&c0));
		// ?->1
		dp[i][4]=min(dp[i][4],dp[i-1][0]+1+(pq==0&&c1));
		// 0->?
		dp[i][0]=min(dp[i][0],dp[i-1][1]+(p0==0&&cq));
		dp[i][0]=min(dp[i][0],dp[i-1][2]+(p0==0&&cq));
		// 1->?
		dp[i][0]=min(dp[i][0],dp[i-1][3]+(p1==0&&cq));
		dp[i][0]=min(dp[i][0],dp[i-1][4]+(p1==0&&cq));
		// 0->0
		dp[i][1]=min(dp[i][1],dp[i-1][1]+(p0==0&&c0));
		dp[i][2]=min(dp[i][2],dp[i-1][2]+(p0==0&&c0));
		// 1->1
		dp[i][3]=min(dp[i][3],dp[i-1][3]+(p1==0&&c1));
		dp[i][4]=min(dp[i][4],dp[i-1][4]+(p1==0&&c1));
		// 0->1
		dp[i][4]=min(dp[i][4],dp[i-1][1]+(p0==0&&c1));
		dp[i][3]=min(dp[i][3],dp[i-1][2]+1+(p0==0&&c1));
		// 1->0
		dp[i][1]=min(dp[i][1],dp[i-1][4]+1+(p1==0&&c0));
		dp[i][2]=min(dp[i][2],dp[i-1][3]+(p1==0&&c0));
	}
	
	cout<<min({dp[N][0],dp[N][1],dp[N][2],dp[N][3],dp[N][4]})<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
