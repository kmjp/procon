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

int N,M;
vector<vector<int>> E[101010];
ll dp[101010];
vector<pair<int,int>> P;

void dfs(int cur,ll v) {
	
	if(dp[cur]==-1LL<<60) {
		dp[cur]=v;
		FORR(e,E[cur]) {
			P.push_back({e[0],e[2]});
			dfs(e[0],v+e[1]);
			P.pop_back();
		}
	}
	else if(dp[cur]!=v) {
		vector<int> A;
		int ok=0;
		FORR(a,P) {
			if(ok) A.push_back(a.second);
			if(a.first==cur) ok=1;
		}
		if(dp[cur]>v) reverse(ALL(A));
		cout<<A.size()<<endl;
		cout<<cur+1<<endl;
		FORR(a,A) {
			cout<<a;
			if(a!=A.back()) cout<<" ";
		}
		cout<<endl;
		exit(0);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		x--,y--;
		E[x].push_back({y,k,i+1});
		E[y].push_back({x,-k,i+1});
	}
	FOR(i,N) dp[i]=-1LL<<60;
	FOR(i,N) if(dp[i]==-1LL<<60) {
		P.push_back({i,0});
		dfs(i,0);
		P.pop_back();
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
