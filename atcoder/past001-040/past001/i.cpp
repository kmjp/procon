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
int S[1010];
ll C[1010];
ll dp[1024];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>s>>C[i];
		FOR(j,N) if(s[j]=='Y') S[i] |= 1<<j;
	}
	FOR(i,1024) dp[i]=1LL<<60;
	dp[0]=0;
	FOR(i,M) {
		FOR(j,1<<N) dp[j|S[i]]=min(dp[j|S[i]],dp[j]+C[i]);
	}
	
	if(dp[(1<<N)-1]==1LL<<60) {
		cout<<-1<<endl;
	}
	else {
		cout<<dp[(1<<N)-1]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
