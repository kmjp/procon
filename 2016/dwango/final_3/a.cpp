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

int K,N;
string S;

bool vis[60][60][60];
bool res[60][60][60];

int dp[60][60][60][2];

bool dpdp(int L,int R,int K) {
	if(vis[L][R][K]) return res[L][R][K];
	if((R-L)%2==1) return false;
	vis[L][R][K]=true;
	dp[L][R][K][0]=1<<20;
	dp[L][R][K][1]=-1<<20;
	
	
	if(L==R) {
		if(K) {
			res[L][R][K]=true;
			dp[L][R][K][0]=0;
			dp[L][R][K][1]=9;
		}
		else {
			if(S[L]>='0' && S[L]<='9') {
				res[L][R][K]=true;
				dp[L][R][K][0]=dp[L][R][K][1]=S[L]-'0';
			}
		}
	}
	else {
		int left=K-(S[R]!='+');
		if(left>=0) {
			for(int M=L;M<R-1;M++) for(int LL=0;LL<=left;LL++) {
				if(dpdp(L,M,LL) && dpdp(M+1,R-1,left-LL)) {
					res[L][R][K]=true;
					dp[L][R][K][0]=min(dp[L][R][K][0],dp[L][M][LL][0]+dp[M+1][R-1][left-LL][0]);
					dp[L][R][K][1]=max(dp[L][R][K][1],dp[L][M][LL][1]+dp[M+1][R-1][left-LL][1]);
				}
			}
		}
		left=K-(S[R]!='-');
		if(left>=0) {
			for(int M=L;M<R-1;M++) for(int LL=0;LL<=left;LL++) {
				if(dpdp(L,M,LL) && dpdp(M+1,R-1,left-LL)) {
					res[L][R][K]=true;
					dp[L][R][K][0]=min(dp[L][R][K][0],dp[L][M][LL][0]-dp[M+1][R-1][left-LL][1]);
					dp[L][R][K][1]=max(dp[L][R][K][1],dp[L][M][LL][1]-dp[M+1][R-1][left-LL][0]);
				}
			}
		}
	}
	return res[L][R][K];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>S;
	N=S.size();
	
	int ma=-10000;
	FOR(i,K+1) if(dpdp(0,N-1,i)) ma=max(ma,dp[0][N-1][i][1]);
	
	if(ma==-10000) _P("NG\n");
	else _P("OK\n%d\n",ma);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
