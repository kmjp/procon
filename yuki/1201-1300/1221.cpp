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
ll A[101010],B[101010];
vector<int> E[101010];
ll dp[101010][3]; // 0-both alive 1-par dead 2-self dead

void dfs(int cur,int pre) {
	dp[cur][2]=A[cur];
	
	ll sum=0;
	vector<ll> add;
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		dp[cur][2]+=max(dp[e][1],dp[e][2]);
		sum+=dp[e][2];
		add.push_back(dp[e][0]-dp[e][2]);
	}
	
	dp[cur][0]=sum+B[cur];
	dp[cur][1]=sum;
	sort(ALL(add));
	reverse(ALL(add));
	int i;
	FOR(i,add.size()) {
		sum+=add[i]+B[cur];
		dp[cur][0]=max(dp[cur][0],sum+B[cur]);
		dp[cur][1]=max(dp[cur][1],sum);
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	cout<<max(dp[0][1],dp[0][2])<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
