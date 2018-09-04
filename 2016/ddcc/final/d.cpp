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

int N,M,C;
ll X[502];
ll dp[505*505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>C;
	FOR(i,501) X[i]=1LL<<40;
	FOR(i,N) {
		cin>>x>>y;
		X[x]=min(X[x],(ll)y);
	}
	
	for(i=499;i>=1;i--) X[i]=min(X[i],X[i+1]);
	
	FOR(i,505*504) dp[i]=1LL<<50;
	dp[0]=0;
	
	int best=1;
	
	ll ret=1LL<<60;
	for(i=1;i<=500;i++) {
		if(X[i]*best<=X[best]*i) best=i;
		for(x=0;x<=500*500;x++) {
			dp[x+i]=min(dp[x+i],dp[x]+X[i]);
			int left=max(M-x,0);
			ret=min(ret,1LL*C*(i-1)+dp[x]+(left+best-1)/best*X[best]);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
