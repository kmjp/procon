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
ll dp[101][5][5][5];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	dp[0][4][4][4]=1;
	
	FOR(i,N) {
		FOR(x,5) FOR(y,5) FOR(z,5) FOR(j,4) {
			if(y==0 && z==1 && j==2) continue;
			if(y==0 && z==2 && j==1) continue;
			if(y==1 && z==0 && j==2) continue;
			if(x==0 && y==1 && j==2) continue;
			if(x==0 && z==1 && j==2) continue;
			(dp[i+1][y][z][j]+=dp[i][x][y][z])%=mo;
		}
	}
	
	ll ret=0;
	FOR(x,5) FOR(y,5) FOR(z,5) ret+=dp[N][x][y][z];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
