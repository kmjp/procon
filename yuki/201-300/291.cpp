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

int L;
string S;
int dp[2][21][21][21][21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int a,b,c,d,e;
	cin>>S;
	L=S.size();
	
	ZERO(dp);
	MINUS(dp);
	int ma=0;
	dp[0][0][0][0][0]=0;
	
	FOR(i,L) {
		int cur=i%2,tar=cur^1;
		memmove(dp[tar],dp[cur],sizeof(dp[tar]));
		FOR(a,21) FOR(b,21) FOR(c,21) FOR(d,21) if(dp[cur][d][c][b][a]>=0) {
			int v=dp[cur][d][c][b][a];
			if(S[i]=='K' || S[i]=='?') if(a<20)      dp[tar][d][c][b][a+1] = max(dp[tar][d][c][b][a+1],v);
			if(S[i]=='U' || S[i]=='?') if(b<20 && a) dp[tar][d][c][b+1][a-1] = max(dp[tar][d][c][b+1][a-1],v);
			if(S[i]=='R' || S[i]=='?') if(c<20 && b) dp[tar][d][c+1][b-1][a] = max(dp[tar][d][c+1][b-1][a],v);
			if(S[i]=='O' || S[i]=='?') if(d<20 && c) dp[tar][d+1][c-1][b][a] = max(dp[tar][d+1][c-1][b][a],v);
			if(S[i]=='I' || S[i]=='?') if(d) ma=max(ma,v+1), dp[tar][d-1][c][b][a] = max(dp[tar][d-1][c][b][a],v+1);
		}
		
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
