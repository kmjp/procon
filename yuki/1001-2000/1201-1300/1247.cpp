#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K,A[303];
ll dp[303][303][303];
ll ret[303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		ret[i]=-1LL<<60;
	}
	FOR(x,302) FOR(y,302) FOR(i,302) dp[x][y][i]=-1LL<<60;
	
	FOR(x,N-1) {
		dp[x][x+1][K-1]=A[x]*(K-1)+A[x+1]*K;
		dp[x+1][x][K-1]=A[x+1]*(K-1)+A[x]*K;
	}
	
	for(i=K-1;i>=0;i--) {
		for(x=0;x<N;x++) for(y=x+1;y<N;y++) {
			// stay
			if(i>=2) {
				dp[x][y][i-2]=max(dp[x][y][i-2],dp[x][y][i]);
				dp[y][x][i-2]=max(dp[y][x][i-2],dp[y][x][i]);
			}
			//left
			if(x&&i) dp[x-1][y][i-1]=max(dp[x-1][y][i-1],dp[x][y][i]+A[x-1]*(i-1));
			//right
			if(y+1<N&&i) dp[y+1][x][i-1]=max(dp[y+1][x][i-1],dp[y][x][i]+A[y+1]*(i-1));
			
			// go to the other side
			if(i>=y-x) {
				dp[x][y][i-(y-x)]=max(dp[x][y][i-(y-x)],dp[y][x][i]);
				dp[y][x][i-(y-x)]=max(dp[y][x][i-(y-x)],dp[x][y][i]);
			}
			else {
				ret[y-i]=max(ret[y-i],dp[y][x][i]);
				ret[x+i]=max(ret[x+i],dp[x][y][i]);
			}
			
		}
	}
	FOR(i,N) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
