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
string S[5];
int mp[256];
int dp[1010][4];
int cnt[1010][4];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	mp['R']=0;
	mp['B']=1;
	mp['W']=2;
	mp['#']=3;
	cin>>N;
	FOR(y,5) {
		cin>>S[y];
		FOR(x,N) cnt[x][mp[S[y][x]]]++;
	}
	
	FOR(x,N) {
		FOR(y,3) dp[x+1][y]=1<<30;
		FOR(i,3) FOR(j,3) if(i!=j) dp[x+1][i]=min(dp[x+1][i],dp[x][j]+5-cnt[x][i]);
		
	}
	
	int ret=1<<30;
	FOR(y,3) ret=min(ret,dp[N][y]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
