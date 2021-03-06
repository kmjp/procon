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
pair<int,int> P[2020];
ll dp[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		P[i]={x,i};
	}
	
	sort(P,P+N);
	reverse(P,P+N);
	
	FOR(x,N+1) FOR(y,N+1) dp[x][y]=-1LL<<60;
	dp[0][0]=0;
	FOR(i,N) {
		ll k=P[i].first;
		r=P[i].second;
		for(x=0;x<=i;x++) {
			y=i-x;
			
			dp[x+1][y]=max(dp[x+1][y],dp[x][y]+abs(r-(x))*k);
			dp[x][y+1]=max(dp[x][y+1],dp[x][y]+abs(r-(N-1-y))*k);
			
		}
	}
	
	ll ret=-1LL<<60;
	FOR(x,N+1) ret=max(ret,dp[x][N-x]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
