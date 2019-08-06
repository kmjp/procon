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
string S;
int sum[404][3];
vector<int> id[3];
int dp[404][404][404][3];
void solve() {
	int i,j,k,l,r,x,y,a,b,c; string s;
	
	cin>>N>>S;
	FOR(i,N) {
		if(S[i]=='R') S[i]=0;
		if(S[i]=='G') S[i]=1;
		if(S[i]=='Y') S[i]=2;
		id[S[i]].push_back(i);
		sum[i+1][0]=sum[i][0];
		sum[i+1][1]=sum[i][1];
		sum[i+1][2]=sum[i][2];
		sum[i+1][S[i]]++;
	}
	FOR(i,404) FOR(j,404) FOR(k,404) FOR(x,3) dp[i][j][k][x]=1<<30;
	if(sum[N][0]) dp[1][0][0][0]=id[0][0];
	if(sum[N][1]) dp[0][1][0][1]=id[1][0];
	if(sum[N][2]) dp[0][0][1][2]=id[2][0];
	for(a=0;a<=sum[N][0];a++) for(b=0;b<=sum[N][1];b++) for(c=0;c<=sum[N][2];c++) FOR(x,3) if(dp[a][b][c][x]<(1<<30)) {
		if(x!=0 && a<sum[N][0]) dp[a+1][b][c][0]=min(dp[a+1][b][c][0],dp[a][b][c][x]+max(0,sum[id[0][a]][1]-b)+max(0,sum[id[0][a]][2]-c));
		if(x!=1 && b<sum[N][1]) dp[a][b+1][c][1]=min(dp[a][b+1][c][1],dp[a][b][c][x]+max(0,sum[id[1][b]][0]-a)+max(0,sum[id[1][b]][2]-c));
		if(x!=2 && c<sum[N][2]) dp[a][b][c+1][2]=min(dp[a][b][c+1][2],dp[a][b][c][x]+max(0,sum[id[2][c]][0]-a)+max(0,sum[id[2][c]][1]-b));
	}
	
	int mi=1<<30;
	FOR(x,3) mi=min(mi,dp[sum[N][0]][sum[N][1]][sum[N][2]][x]);
	if(mi==1<<30) mi=-1;
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
