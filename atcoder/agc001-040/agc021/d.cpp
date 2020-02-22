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

int N,K;
string S;

int dp[303][303][303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	N=S.size();
	
	FOR(i,N) {
		dp[i][i][K]=1;
		if(i<N-1) {
			dp[i][i+1][K]=1+(S[i]==S[i+1]);
			if(K) dp[i][i+1][K-1]=2;
		}
	}
	
	
	
	for(i=1;i<=N;i++) {
		for(int L=0;L+i<=N;L++) {
			int R=L+i-1;
			for(k=0;k<=K;k++) {
				if(L) dp[L-1][R][k]=max(dp[L-1][R][k],dp[L][R][k]);
				if(R<N-1) dp[L][R+1][k]=max(dp[L][R+1][k],dp[L][R][k]);
				if(L&&R<N-1) {
					if(dp[L][R][k]==0) {
						dp[L-1][R+1][k]=max(dp[L-1][R+1][k],1+(S[L-1]==S[R+1]));
					}
					else {
						dp[L-1][R+1][k]=max(dp[L-1][R+1][k],dp[L][R][k]+2*(S[L-1]==S[R+1]));
					}
					if(k) dp[L-1][R+1][k-1]=max(dp[L-1][R+1][k-1],dp[L][R][k]+2);
				}
			}
		}
	}
	
	int ma=0;
	FOR(i,K+1) ma=max(ma,dp[0][N-1][i]);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
