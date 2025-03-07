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
ll X;
ll A[202020];
ll dp[202020];
int P[202020];
set<int> S;
ll dfs(int cur) {
	if(dp[cur]!=-1) return dp[cur];
	dp[cur]=1LL<<60;
	if(P[cur]!=-1) {
		dp[cur]=A[cur]+dfs(P[cur]);
	}
	else {
		dp[cur]=A[cur];
	}
	return dp[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	MINUS(dp);
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
	}
	int ret=-1;
	FOR(i,N) if(dfs(i)<=X) ret=i+1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
