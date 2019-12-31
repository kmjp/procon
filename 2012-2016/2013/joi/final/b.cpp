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

int A,B;
string S,T;
int dp[2020][2020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	cin>>S>>T;
	FORR(c,S) c=c=='I';
	FORR(c,T) c=c=='I';
	FOR(x,A+1) FOR(y,B+1) dp[x][y][1]=-101010;
	FOR(x,A+1) FOR(y,B+1) {
		FOR(i,2) {
			if(x<A && S[x]!=i) dp[x+1][y][i^1]=max(dp[x+1][y][i^1],dp[x][y][i]+1);
			if(y<B && T[y]!=i) dp[x][y+1][i^1]=max(dp[x][y+1][i^1],dp[x][y][i]+1);
		}
	}
	int ma=0;
	FOR(x,A+1) FOR(y,B+1) ma=max(ma,dp[x][y][1]);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
