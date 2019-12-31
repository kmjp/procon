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

ll dp[21][300005];
ll sum[300005];
int Q;
ll X;
ll p10[22];

ll dfs(int d,ll K,int L) {
	ll ret=0;
	int i;
	if(d==0) return L;
	FOR(i,10) {
		if(K<=dp[d][L-(i<<d)]) {
			ret = p10[d]*i + dfs(d-1,K,L-(i<<d));
			break;
		}
		else {
			K -= dp[d][L-(i<<d)];
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0]=1;
	int d;
	for(d=0;d<20;d++) FOR(x,300000) if(dp[d][x]) FOR(y,10) if(x+(y<<d)<300000) dp[d+1][x+(y<<d)] += dp[d][x];
	p10[0]=1;
	FOR(i,21) p10[i+1]=p10[i]*10;
	
	FOR(i,300000) sum[i]=(i?sum[i-1]:0)+dp[d][i];
	
	cin>>Q;
	while(Q--) {
		cin>>X;
		if(X==1) {
			cout<<0<<endl;
			continue;
		}
		x=lower_bound(sum,sum+300000,X)-sum;
		X-=sum[x-1];
		cout<<dfs(20,X,x)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
