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

int N,K;
ll dp[1<<20][20][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	K--;
	dp[1<<K][K][0]=1;
	
	FOR(i,1<<N) {
		FOR(j,N) FOR(k,2) if(dp[i][j][k]) {
			FOR(x,N) if((i&(1<<x))==0) {
				if(j<x) dp[i^(1<<x)][x][k]+=dp[i][j][k];
				if(j>x && k==0) dp[i^(1<<x)][x][1]+=dp[i][j][k];
			}
		}
	}
	
	ll ret=0;
	FOR(i,N) ret+=dp[(1<<N)-1][i][1];
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
