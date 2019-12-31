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

int N,L,M;
int T[2020],P[2020];
ll dp[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	if(N>2000 || L>2000) return;
	
	FOR(i,N) cin>>T[i]>>P[i];
	
	memset(dp,0x3f,sizeof(dp));
	FOR(i,L+1) dp[0][i]=0;
	FOR(i,N) {
		ll ma=1LL<<60;
		if(i&&T[i]==T[i-1]) {
			FOR(x,L+1) dp[i+1][x]=dp[i][x]+abs(x-P[i]);
		}
		else {
			FOR(x,L+1) dp[i+1][x]=min(dp[i][x],x?dp[i+1][x-1]:9999999);
			FOR(x,L+1) _P("%d:%lld ",x,dp[i+1][x]);
			_P("\n");
			FOR(x,L+1) {
				ma=min(ma,dp[i][x]);
				dp[i+1][x]=abs(x-P[i])+ma;
			}
		}
	}
	cout<<*min_element(dp[N],dp[N]+L+1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
