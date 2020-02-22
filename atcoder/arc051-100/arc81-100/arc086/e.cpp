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
int P[201010];
int D[202020];
int VD[202020];
vector<int> E[202020];
ll p2[202020];
ll mo=1000000007;

deque<vector<ll>> dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	VD[0]++;
	FOR(i,N) {
		cin>>P[i+1];
		E[P[i+1]].push_back(i+1);
		D[i+1]=D[P[i+1]]+1;
		VD[D[i+1]]++;
	}
	N++;
	
	p2[0]=1;
	FOR(i,N) p2[i+1]=p2[i]*2%mo;
	
	for(i=N-1;i>=0;i--) {
		FORR(e,E[i]) {
			if(dp[e].size()>dp[i].size()) swap(dp[e],dp[i]);
		}
		int ma=0;
		FORR(e,E[i]) {
			ma=max(ma,(int)dp[e].size());
			FOR(j,dp[e].size()) {
				ll a[3]={};
				a[0]=dp[i][j][0]*dp[e][j][0]%mo;
				a[1]=(dp[i][j][0]*dp[e][j][1]+dp[i][j][1]*dp[e][j][0])%mo;
				a[2]=(dp[i][j][2]*(dp[e][j][0]+dp[e][j][1])+dp[i][j][1]*dp[e][j][1])%mo;
				dp[i][j][0]=a[0];
				dp[i][j][1]=a[1];
				dp[i][j][2]=a[2];
			}
		}
		FOR(j,ma) {
			(dp[i][j][0]+=dp[i][j][2])%=mo;
			dp[i][j][2]=0;
		}
		
		dp[i].push_front({1,1,0});
	}
	
	ll ret=0;
	FOR(i,dp[0].size()) ret+=dp[0][i][1]*p2[N-VD[i]]%mo;
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
