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

string A;
int ret;

int dp[1010][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(dp);
	cin>>A;
	dp[0][0]=0;
	FOR(i,A.size()) {
		j = A[A.size()-1-i]-'0';
		FOR(x,10) {
			dp[i+1][x>j]=max(dp[i+1][x>j],dp[i][0] +(j==0 && x==0));
			if(j-x>0 || i==0) ret=max(ret,dp[i+1][x>j]);
			dp[i+1][(x+1)>j]=max(dp[i+1][(x+1)>j],dp[i][1] +(j==9 && x==9));
			if(j!=(x+1) || i==0) ret=max(ret,dp[i+1][(x+1)>j]);
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
