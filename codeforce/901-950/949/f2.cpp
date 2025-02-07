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

int T,N,M,A[202020];
vector<int> E[202020];
int dp[25252][4000];

void dfs(int cur) {
	int i;
	if(E[cur].empty()) {
		for(i=1;i<=M;i++) dp[cur][i]=(i==A[cur])?(1<<28):0;
	}
	else if(E[cur].size()==1) {
		int x=E[cur][0];
		dfs(x);
		int mi=1<<28;
		for(i=1;i<=M;i++) if(i!=A[cur]) mi=min(mi,dp[x][i]+i);
		if(cur==0) {
			cout<<mi<<endl;
		}
		else {
			for(i=1;i<=M;i++) dp[cur][i]=(i==A[cur])?(1<<28):min(dp[x][i],mi);
		}
	}
	else {
		int x=E[cur][0];
		int y=E[cur][1];
		dfs(x);
		dfs(y);
		int mix=1<<28,miy=1<<28,k=1<<28;
		for(i=1;i<=M;i++) if(i!=A[cur]) {
			mix=min(mix,dp[x][i]+i);
			miy=min(miy,dp[y][i]+i);
			k=min(k,dp[x][i]+dp[y][i]+i);
		}
		k=min(k,mix+miy);
		if(cur==0) {
			cout<<k<<endl;
		}
		else {
			for(i=1;i<=M;i++) dp[cur][i]=(i==A[cur])?(1<<28):min({dp[x][i]+miy,dp[y][i]+mix,k});
		}
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		M=min(N+2,3900);
		FOR(i,N) {
			cin>>A[i];
			E[i].clear();
		}
		FOR(i,N-1) {
			cin>>x;
			E[x-1].push_back(i+1);
		}
		dfs(0);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
