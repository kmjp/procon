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
string S[2];
ll dp[3030][3030];
ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>S[0]>>S[1];
	dp[0][0]=1;
	FOR(x,N+1) FOR(y,N+1) {
		char nex="BW"[(x+y)%2];
		if(x<N && S[0][x]==nex) (dp[x+1][y]+=dp[x][y])%=mo;
		if(y<N && S[1][y]==nex) (dp[x][y+1]+=dp[x][y])%=mo;
	}
	
	cout<<dp[N][N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
