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

int N,M,K;

int A[60],B[60];
ll AS,BS;
ll ok[22222*110+5];
ll *dp=&ok[22222*55+3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>A[i], AS+=A[i];
	FOR(i,M) cin>>B[i], BS+=B[i];
	sort(A,A+N);
	sort(B,B+M);
	
	ll ma=0;
	if(K==1) {
		FOR(x,N) FOR(y,M) ma=max(ma,(AS-A[x]+B[y])*(BS+A[x]-B[y]));
	}
	else {
		int MA=22222*55;
		K=min(K,55);
		dp[0]=1;
		FOR(i,N) for(x=MA-A[i];x>=0;x--) dp[x+A[i]] |= dp[x]<<1;
		FOR(i,MA+1) dp[i] &= ((1LL<<(K+1))-1);
		FOR(i,M) for(x=-MA+B[i];x<=MA;x++) dp[x-B[i]] |= dp[x]>>1;
		
		for(i=-MA;i<=MA;i++) if(dp[i]&1) ma=max(ma,(AS-i)*(BS+i));
	}
	
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
