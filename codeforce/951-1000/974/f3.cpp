#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,C;
ll A[202020];
ll dp[202020][2];
vector<int> E[202020];

void dfs(int cur,int pre) {
	dp[cur][0]=0;
	dp[cur][1]=A[cur];
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		dp[cur][0]=max(dp[cur][0]+dp[e][0],dp[cur][0]+dp[e][1]);
		dp[cur][1]=max(dp[cur][1]+dp[e][0],dp[cur][1]+dp[e][1]-2*C);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>C;
		FOR(i,N) {
			cin>>A[i];
			E[i].clear();
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		dfs(0,0);
		cout<<max(dp[0][0],dp[0][1])<<endl;
	}
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
