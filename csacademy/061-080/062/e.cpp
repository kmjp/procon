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
map<pair<ll,ll>,ll> M;
vector<int> E[2][303030];

ll p2[2][303030];
ll mo[2]={1000000007,1000000009};
ll dp[2][303030];
ll ret;

void dfs(int cur,int pre) {
	dp[0][cur]=p2[0][cur];
	dp[1][cur]=p2[1][cur];
	FORR(e,E[0][cur]) if(e!=pre) {
		dfs(e,cur);
		(dp[0][cur]+=dp[0][e])%=mo[0];
		(dp[1][cur]+=dp[1][e])%=mo[1];
	}
	if(cur!=1) M[{dp[0][cur],dp[1][cur]}]++;
}
void dfs2(int cur,int pre) {
	dp[0][cur]=p2[0][cur];
	dp[1][cur]=p2[1][cur];
	FORR(e,E[1][cur]) if(e!=pre) {
		dfs2(e,cur);
		(dp[0][cur]+=dp[0][e])%=mo[0];
		(dp[1][cur]+=dp[1][e])%=mo[1];
	}
	if(cur!=1) ret+=M[{dp[0][cur],dp[1][cur]}];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	p2[0][0]=p2[1][0]=1;
	FOR(i,N) {
		p2[0][i+1]=p2[0][i]*2%mo[0];
		p2[1][i+1]=p2[1][i]*2%mo[1];
	}
	
	for(i=2;i<=N;i++) {
		cin>>x;
		E[0][x].push_back(i);
	}
	for(i=2;i<=N;i++) {
		cin>>x;
		E[1][x].push_back(i);
	}
	dfs(1,-1);
	ZERO(dp);
	dfs2(1,-1);
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
