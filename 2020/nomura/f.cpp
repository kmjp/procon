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

int N,M;
const ll mo=1000000007;

ll dp[5050][5050];
ll p2[5050],r2[5050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M+1) dp[0][i]=1;
	
	p2[0]=r2[0]=1;
	FOR(i,5010) {
		p2[i+1]=p2[i]*2%mo;
		r2[i+1]=r2[i]*(mo+1)/2%mo;
	}
	
	
	for(i=1;i<=N;i++) {
		dp[i][0]=1;
		ll sum=0;
		for(x=1;x<=M;x++) {
			// 000111
			(dp[i][x]+=dp[i-1][x]*(x+1))%=mo;
			if(x>=2) (sum+=(x-1)*dp[i-1][x-1]%mo*p2[M-x])%=mo;
			(dp[i][x]+=sum*r2[M-x])%=mo;
			/*
			// 00111000
			for(int len=2;len<=x;len++) {
				(dp[i][x]+=dp[i-1][x-(len-1)]*p2[len-2]%mo*(x-len+1))%=mo;
			}
			*/
		}
	}
	cout<<dp[N][M]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
