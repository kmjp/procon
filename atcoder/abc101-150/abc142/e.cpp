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
ll mi[1<<12];
ll dp[1<<12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,1<<N) mi[i]=dp[i]=1LL<<60;
	FOR(i,M) {
		int mask=0;
		cin>>x>>y;
		FOR(j,y) {
			cin>>r;
			mask |= 1<<(r-1);
		}
		mi[mask]=min(mi[mask],(ll)x);
	}
	
	dp[0]=0;
	FOR(x,1<<N) FOR(y,1<<N) dp[x|y]=min(dp[x|y],dp[x]+mi[y]);
	
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
