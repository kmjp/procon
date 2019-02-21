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
int P[2020],NC[2020];
vector<int> E[2020];
int C[2020];

ll dp[2020][2020][3];
ll mo=1000000007;

ll fact[2020];
ll dp2[2020][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<N;i++) {
		cin>>P[i];
		P[i]--;
		E[P[i]].push_back(i);
	}
	
	fact[0]=1;
	FOR(i,N) fact[i+1]=fact[i]*(i+1)%mo;
	
	
	
	for(i=N-1;i>=0;i--) {
		C[i]=1;
		dp[i][1][0]=1;
		
		FORR(e,E[i]) {
			
			for(x=1;x<=C[i];x++) for(y=1;y<=C[e];y++) {
				// not con
				(dp2[x+y][0]+=dp[i][x][0]*(dp[e][y][0]+2*dp[e][y][1]+2*dp[e][y][2]))%=mo;
				(dp2[x+y][1]+=dp[i][x][1]*(dp[e][y][0]+2*dp[e][y][1]+2*dp[e][y][2]))%=mo;
				(dp2[x+y][2]+=dp[i][x][2]*(dp[e][y][0]+2*dp[e][y][1]+2*dp[e][y][2]))%=mo;
				// con
				(dp2[x+y-1][1]+=dp[i][x][0]*(dp[e][y][0]+dp[e][y][1]))%=mo;
				(dp2[x+y-1][2]+=dp[i][x][1]*(dp[e][y][0]+dp[e][y][1]))%=mo;
			}
			
			
			C[i]+=C[e];
			FOR(j,C[i]+2) FOR(x,3) dp[i][j][x]=dp2[j][x], dp2[j][x]=0;
		}
	}
	
	ll ret=0;
	for(i=1;i<=N;i++) {
		if((N-i)%2==0) ret+=(dp[0][i][0]+2*dp[0][i][1]+2*dp[0][i][2])*fact[i]%mo;
		else ret-=(dp[0][i][0]+2*dp[0][i][1]+2*dp[0][i][2])*fact[i]%mo;
	}
	
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
