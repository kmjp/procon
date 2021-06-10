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


int N,K;
vector<pair<int,int>> E[101010];
ll D[202020];
int C[202020];
vector<pair<int,ll>> V;
ll ret=0;
int dfs(int cur,int pre,ll d) {
	D[cur]=d;
	if(cur&&E[cur].size()==1) {
		C[cur]=1;
		ret+=d;
	}
	ll sum=0;
	int up=0;
	FORR2(e,c,E[cur]) if(e==pre) up=c;
	FORR2(e,c,E[cur]) if(e!=pre) {
		C[cur]+=dfs(e,cur,d+c);
	}
	V.push_back({up,1LL*C[cur]*up});
	return C[cur];
	
}

ll dp[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	dfs(0,0,0);
	FORR2(c,v,V) {
		for(i=K;i>=c;i--) dp[i]=max(dp[i],dp[i-c]+v);
	}
	cout<<ret+dp[K]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
