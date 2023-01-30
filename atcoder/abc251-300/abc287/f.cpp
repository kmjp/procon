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

int N;
vector<int> E[5050];
const ll mo=998244353;

ll dp[5050][5050][2];
int C[5050];

int dfs(int cur,int pre) {
	C[cur]=1;
	ll from[5050][2]={};
	from[0][0]=1;
	from[1][1]=1;
	
	int x,y;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		ll to[5050][2]={};
		FOR(x,C[cur]+1) FOR(y,C[e]+1) {
			(to[x+y][0]+=from[x][0]*dp[e][y][0])%=mo;
			(to[x+y][0]+=from[x][0]*dp[e][y][1])%=mo;
			(to[x+y][1]+=from[x][1]*dp[e][y][0])%=mo;
			if(y) (to[x+y-1][1]+=from[x][1]*dp[e][y][1])%=mo;
		}
		
		swap(from,to);
		C[cur]+=C[e];
	}
	
	FOR(x,C[cur]+1) {
		dp[cur][x][0]=from[x][0];
		dp[cur][x][1]=from[x][1];
	}
	return C[cur];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	for(x=1;x<=N;x++) {
		cout<<(dp[0][x][0]+dp[0][x][1])%mo<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
