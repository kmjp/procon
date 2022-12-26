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

int N;
int C[10][10];

ll dp[1024][1024][11];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>C[y][x];
	
	FOR(x,1024) FOR(y,1024) FOR(r,10) dp[x][y][r]=1LL<<60;
	FOR(r,N) dp[1<<r][0][r]=0;
	int m1,m2;
	ll ret=1LL<<60;
	FOR(m2,1<<N) FOR(m1,1<<N) FOR(x,N) if(dp[m1][m2][x]<1LL<<60) {
		FOR(y,N) if((m1&(1<<y))==0) { //‰‰ñ
			int nm1,nm2;
			if(m2&(1<<x)) {
				nm1=m1|(1<<y);
				nm2=m2;
				dp[nm1][nm2][y]=min(dp[nm1][nm2][y],dp[m1][m2][x]+C[x][y]);
				if(nm1==(1<<N)-1) ret=min(ret,dp[nm1][nm2][y]);
			}
			else {
				nm1=(m1|(1<<y))^(1<<x);
				nm2=m2^(1<<x);
				dp[nm1][nm2][y]=min(dp[nm1][nm2][y],dp[m1][m2][x]+C[x][y]);
			}
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
