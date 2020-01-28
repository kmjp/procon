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

int H,N;
int A[10101],B[101010];
ll dp[20100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>N;
	FOR(i,20001) dp[i]=1LL<<60;
	dp[0]=0;
	FOR(i,N) {
		cin>>x>>y;
		FOR(j,H) dp[j+x]=min(dp[j+x],dp[j]+y);
	}
	
	ll mi=1LL<<60;
	for(i=H;i<=20000;i++) mi=min(mi,dp[i]);
	cout<<mi<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
