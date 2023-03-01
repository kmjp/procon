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
vector<int> E[202020];
int C[202020];

int dp[202020][2];

void dfs(int cur,int pre) {
	int from[2]={1<<20,1<<20};
	from[C[cur]]=0;
	
	FORR(e,E[cur]) if(e!=pre) {
		int to[2]={1<<20,1<<20};
		dfs(e,cur);
		chmin(to[0],from[0]+dp[e][0]);
		chmin(to[1],from[1]+dp[e][0]);
		chmin(to[1],from[0]+dp[e][1]+1);
		chmin(to[0],from[1]+dp[e][1]+1);
		
		
		
		swap(from,to);
	}
	dp[cur][0]=from[0];
	dp[cur][1]=from[1];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) {
		cin>>C[i];
		C[i]^=1;
	}
	
	dfs(0,0);
	x=dp[0][0];
	if(x>=1<<20) x=-1;
	cout<<x<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
