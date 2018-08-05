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

int D,G;
int P[101],C[101];
int dp[1110];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>G;
	
	FOR(i,1101) dp[i]=-1<<30;
	dp[0]=0;
	for(i=1;i<=D;i++) {
		cin>>x>>y;
		for(j=1000;j>=0;j--) {
			for(k=1;k<x;k++) dp[j+k]=max(dp[j+k],dp[j]+k*i*100);
			dp[j+x]=max(dp[j+x],dp[j]+x*i*100+y);
		}
		
	}
	
	FOR(j,1001) {
		if(dp[j]>=G) return _P("%d\n",j);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
