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

int N,M;
string S,T;
int dp[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T;
	for(x=N;x>=0;x--) for(y=M;y>=0;y--) {
		if(x==N && y==M) continue;
		if(x<N && y<M && S[x]==T[y]) dp[x][y]=dp[x+1][y+1];
		else {
			dp[x][y]=N+M;
			if(x<N) dp[x][y]=min(dp[x][y],dp[x+1][y]+1);
			if(y<M) dp[x][y]=min(dp[x][y],dp[x][y+1]+1);
			if(x<N && y<M) dp[x][y]=min(dp[x][y],dp[x+1][y+1]+1);
		}
	}
	
	cout<<dp[0][0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
