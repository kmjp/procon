#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int P[2001],Q[2001];
ll mo=1000000007;
ll memo[2005][2005];

ll dp[2005][2005];

ll dodo(int p,int q) {
	if(p>N || q>N) return 0;
	if(p==N || q==N) return 1;
	ll& ret=memo[p][q];
	if(ret>=0) return ret;
	ret=0;
	if(P[p]!=Q[q]) return ret=(dodo(p+1,q)+dodo(p,q+1))%mo;
	int x,i;
	for(x=1;x<N;x++) {
		if(p+x>=N || q+x>=N) break;
		if(P[p+x]!=Q[q+x]) break;
	}
	for(i=1;i<=x;i++) ret+=dp[i][i]*dodo(p+i,q+i)%mo;
	if(p+x<N) for(i=0;i<x;i++) ret+=dp[x][i]*dodo(p+x+1,q+i)%mo;
	if(q+x<N) for(i=0;i<x;i++) ret+=dp[x][i]*dodo(p+i,q+x+1)%mo;
	ret %= mo;
	
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0]=dp[1][0]=1;
	FOR(x,2003) FOR(y,x) {
		dp[x+1][y]=(dp[x+1][y]+dp[x][y])%mo;
		dp[x][y+1]=(dp[x][y+1]+dp[x][y])%mo;
	}
	
	cin>>N;
	FOR(i,N) cin>>P[i],P[i]--;
	FOR(i,N) cin>>Q[i],Q[i]--;
	MINUS(memo);
	cout<<dodo(0,0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
