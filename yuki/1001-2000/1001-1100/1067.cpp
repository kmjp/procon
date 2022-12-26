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

int N,Q;
int A[6060];
ll dp[6060][6060];
const ll mo=998244353;
ll mu[6060];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	dp[N][0]=1;
	for(i=N-1;i>=0;i--) {
		FOR(j,N) {
			(dp[i][j]+=dp[i+1][j]*(A[i]-1))%=mo;
			(dp[i][j+1]+=dp[i+1][j])%=mo;
		}
	}
	mu[0]=1;
	FOR(i,N) mu[i+1]=mu[i]*A[i]%mo;
	
	while(Q--) {
		int L,R;
		cin>>L>>R>>y;
		ll ret=0;
		for(i=L;i<=R;i++) {
			x=lower_bound(A,A+N,i)-A;
			ret^=dp[x][y]*mu[x]%mo;
		}
		cout<<ret<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
