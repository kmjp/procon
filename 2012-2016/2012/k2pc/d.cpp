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


int K,R;
int mask[3030300];
ll dp[3030300][2][2];
const ll mo=100000;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>R;
	FOR(i,R) {
		cin>>x>>y;
		mask[y]|=x;
	}
	dp[0][0][0]=1;
	
	for(i=1;i<=K;i++) {
		if(mask[i]==3) return _P("0\n");
		if((mask[i]&1)==0) {
			dp[i][0][1]=(dp[i-1][0][0]+dp[i-1][1][0])%mo;
		}
		if((mask[i]&2)==0) {
			dp[i][1][0]=(dp[i-1][0][0]+dp[i-1][0][1])%mo;
		}
		if((mask[i]&3)==0) {
			dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][0][1])%mo;
		}
	}
	
	cout<<dp[K][0][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
