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
int A[2010],B[2010];
ll mo=1000000007;
ll dp[2010][2010];
ll lesspat[2010][2010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	FOR(y,N+1) {
		lesspat[0][y]=1;
		FOR(x,N+1) {
			if(x+1<y) (lesspat[x+1][y] += lesspat[x][y])%=mo;
			(lesspat[x][y+1] += lesspat[x][y])%=mo;
		}
	}
	
	dp[0][0]=1;
	FOR(y,N) FOR(x,N) {
		ll& ret=dp[x][y];
		if(x||y) ret = (((x)?dp[x-1][y]:0)+((y)?dp[x][y-1]:0))%mo;
		
		if(A[x]==B[y]) {
			int same=0;
			i=x-1,j=y-1;
			while(i>=0 && j>=0) {
				if(A[i]==B[j]) same++, ret += mo-dp[i][j]*lesspat[same-1][same]%mo;
				i--, j--;
			}
		}
		ret %= mo;
	}
	
	cout<<dp[N-1][N-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
