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
vector<int> R[201010],B[201010];
ll dp[202020][3][2];

void dfs(int cur,int pre,int d) {
	if(B[cur].size()%2) {
		dp[cur][0][0]=1LL<<40;
		dp[cur][0][1]=d;
		dp[cur][1][0]=0;
		dp[cur][1][1]=1LL<<40;;
		dp[cur][2][0]=dp[cur][2][1]=1LL<<40;
	}
	else {
		dp[cur][0][0]=0;
		dp[cur][0][1]=1LL<<40;
		dp[cur][1][0]=1LL<<40;
		dp[cur][1][1]=1LL<<40;;
		dp[cur][2][0]=dp[cur][2][1]=1LL<<40;
	}
	FORR(e,R[cur]) if(e!=pre) {
		dfs(e,cur,d+1);
		ll p[3][2];
		int a,b;
		FOR(a,3) FOR(b,2) p[a][b]=dp[cur][a][b];
		FOR(a,3) FOR(b,2) dp[cur][a][b]=1LL<<40;
		FOR(a,3) for(b=0;a+b<=2;b++) {
			dp[cur][a+b][0]=min({dp[cur][a+b][0],p[a][0]+dp[e][b][0],p[a][1]+dp[e][b][1]-2*d});
			dp[cur][a+b][1]=min({dp[cur][a+b][1],p[a][0]+dp[e][b][1],p[a][1]+dp[e][b][0]});
		}
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		R[x-1].push_back(y-1);
		R[y-1].push_back(x-1);
	}
	FOR(i,N-1) {
		cin>>x>>y;
		B[x-1].push_back(y-1);
		B[y-1].push_back(x-1);
	}
	dfs(0,-1,0);
	cout<<(N-1)+min(dp[0][0][0],dp[0][2][0])<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
