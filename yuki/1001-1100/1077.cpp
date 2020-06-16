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
int A[1010],B[1010];;

ll dp[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		B[i]=A[i];
	}
	sort(B,B+N);
	FOR(x,N+1) FOR(y,N+1) dp[x][y]=1LL<<60;
	
	FOR(i,N) dp[0][i]=abs(B[i]-A[0]);
	
	for(i=1;i<N;i++) {
		ll mi=1LL<<60;
		for(j=0;j<N;j++) {
			mi=min(mi,dp[i-1][j]);
			dp[i][j]=mi+abs(B[j]-A[i]);
		}
	}
	
	ll ret=1LL<<60;
	FOR(i,N) ret=min(ret,dp[N-1][i]);
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
