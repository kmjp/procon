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
int A[2][20];

int dp[1<<18][18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) cin>>A[0][i];
	FOR(i,N) cin>>A[1][i];
	FOR(i,1<<18) FOR(x,18) dp[i][x]=1010100;
	
	FOR(i,N) dp[1<<i][i]=i;
	int mask;
	FOR(mask,(1<<N)-1) {
		FOR(i,N) if((mask&(1<<i)) && dp[mask][i]<1000000) {
			int b=__builtin_popcount(mask);
			int cur=A[abs(i-b-1)%2][i];
			FOR(x,N) if((mask&(1<<x))==0) {
				int nex=A[abs(x-b)%2][x];
				int num=__builtin_popcount((mask^(0xfffff))&((1<<x)-1));
				if(nex>=cur) {
					dp[mask|(1<<x)][x]=min(dp[mask|(1<<x)][x],dp[mask][i]+num);
				}
			}
		}
	}
	
	
	int mi=1010100;
	FOR(i,N) mi=min(mi,dp[(1<<N)-1][i]);
	
	if(mi>=1000000) {
		cout<<-1<<endl;
	}
	else {
		cout<<mi<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
