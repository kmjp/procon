#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int P[10101];
ll dp[2][100020];
ll sum,tsum;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) cin>>P[i], sum+=P[i];
	sort(P,P+M);
	reverse(P,P+M);
	
	MINUS(dp);
	dp[0][P[0]]=0;
	tsum=P[0];
	for(i=1;i<M;i++) {
		int cur=(i-1)%2, tar=cur^1;
		MINUS(dp[tar]);
		FOR(x,100001) if(dp[cur][x]>=0) {
			// left
			dp[tar][x+P[i]]=max(dp[tar][x+P[i]],dp[cur][x]+x*(sum-x));
			// right
			dp[tar][x]=max(dp[tar][x],dp[cur][x]+(sum-(tsum-x))*(tsum-x));
		}
		tsum+=P[i];
	}
	
	ll ma=0;
	FOR(x,100001) if(dp[(M+1)%2][x]>=0) ma=max(ma,dp[(M+1)%2][x]+(N-M+1)*(sum-x)*x);
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
