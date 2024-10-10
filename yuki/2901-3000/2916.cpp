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

int N,M,C;
ll dp[10][101010];
vector<vector<int>> E[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>C;
	FOR(i,M) {
		cin>>x>>y>>k>>r;
		E[x-1].push_back({y-1,k,r});
		E[y-1].push_back({x-1,k,r});
	}
	FOR(i,C+1) {
		FOR(j,N) dp[j][i]=-1;
		dp[N-1][i]=i;
		
		FOR(j,N) FORR(e,E[j]) {
			int c=i/e[1]+e[2];
			if(c<=i) dp[j][i]=max(dp[j][i],dp[e[0]][i-c]);
		}
		
	}
	
	for(i=1;i<=C;i++) cout<<dp[0][i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
