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
ll dp[101010][3];
ll rdp[101010][3];
int LJ[101010];
int RI[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	
	ll ma=0;
	FOR(i,N) {
		FOR(j,3) dp[i+1][j]=dp[i][j];
		if(i) LJ[i]=LJ[i-1];
		if(S[i]=='J') dp[i+1][0]++, LJ[i]++;
		if(S[i]=='O') dp[i+1][1]+=dp[i][0];
		if(S[i]=='I') dp[i+1][2]+=dp[i][1];
		ma=max(ma,dp[i+1][1]);
	}
	for(i=N-1;i>=0;i--) {
		FOR(j,3) rdp[i][j]=rdp[i+1][j];
		RI[i]=RI[i+1];
		if(S[i]=='J') rdp[i][2]+=rdp[i][1];
		if(S[i]=='O') rdp[i][1]+=rdp[i][0];
		if(S[i]=='I') rdp[i][0]++, RI[i]++;
		ma=max(ma,rdp[i][1]);
	}
	
	FOR(i,N) ma=max(ma,(ll)LJ[i]*RI[i+1]);
	
	cout<<dp[N][2]+ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
