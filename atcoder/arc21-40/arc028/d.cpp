#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,Q;
int A[3000];
ll mo=1000000007;
ll dp1[2005][2005],dp2[2005][2005];

void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>N>>M>>Q;
	FOR(i,N) cin>>A[i];
	
	FOR(i,N+1) dp1[i][0]=1;
	FOR(i,N) FOR(j,M) {
		dp1[i+1][j+1]=dp1[i+1][j]+dp1[i][j+1];
		if(j-A[i]>=0) dp1[i+1][j+1]+=mo-dp1[i][j-A[i]];
		dp1[i+1][j+1]%=mo;
	}
	FOR(i,N) FOR(j,M+1) {
		dp2[i][j]=dp1[N][j];
		if(j) dp2[i][j]+=mo-dp1[N][j-1];
		if(j-1-A[i]>=0) dp2[i][j]+=dp2[i][j-1-A[i]];
		dp2[i][j]%=mo;
	}
	
	FOR(k,Q) {
		cin>>x>>y;
		_P("%lld\n",dp2[x-1][M-y]);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
