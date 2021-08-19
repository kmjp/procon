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
vector<int> E[2020];
int C[2020];
const ll mo=1000000007;

ll dp[2020][2020][3]; // 0-not 1-covered 2-placed

void dfs(int cur,int pre) {
	ll from[2020][3]={};
	C[cur]=1;
	from[0][0]=1;
	from[1][2]=1;
	FORR(e,E[cur]) if(e!=pre) {
		ll to[2020][3]={};
		dfs(e,cur);
		int x,y;
		FOR(x,C[cur]+1) FOR(y,C[e]+1) {
			(to[x+y+1][2]+=from[x][2]*dp[e][y][0])%=mo;
			(to[x+y][2]+=from[x][2]*(dp[e][y][1]+dp[e][y][2]))%=mo;
			(to[x+y][1]+=from[x][1]*(dp[e][y][0]+dp[e][y][1]+dp[e][y][2]))%=mo;
			(to[x+y][0]+=from[x][0]*(dp[e][y][0]+dp[e][y][1]))%=mo;
			(to[x+y+1][1]+=from[x][0]*(dp[e][y][2]))%=mo;
		}
		C[cur]+=C[e];
		
		
		
		swap(from,to);
	}
	
	int x,y;
	FOR(x,2001) FOR(y,3) dp[cur][x][y]=from[x][y];
	
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
	FOR(i,N+1) {
		ll ret=dp[0][i][0]+dp[0][i][1]+dp[0][i][2];
		cout<<ret%mo<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
