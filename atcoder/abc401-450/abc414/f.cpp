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

int T;
int N;
int K;
int id;
vector<int> E[202020];
vector<int> C[202020][21];
vector<pair<int,int>> E2[202020*53];
int dp[202020*53];
void dfs(int cur,int pre) {
	E[cur].erase(remove(ALL(E[cur]),pre),E[cur].end());
	C[cur][0]={cur};
	int i,j;
	FORR(e,E[cur]) {
		dfs(e,cur);
		FOR(i,K) {
			FORR(a,C[e][i]) C[cur][i+1].push_back(a);
		}
	}
	FORR(v,C[cur][K]) E2[cur].push_back({v,1}),E2[v].push_back({cur,1});
	for(i=1;i<K;i++) {
		FOR(j,E[cur].size()) {
			FORR(c,C[E[cur][j]][i-1]) E2[c].push_back({id+j,1});
			if(j) FORR(c,C[E[cur][j]][K-i-1]) E2[id+j-1].push_back({c,0});
			if(j) E2[id+j-1].push_back({id+j,0});
		}
		id+=E[cur].size();
		FOR(j,E[cur].size()) {
			FORR(c,C[E[cur][j]][i-1]) E2[c].push_back({id+j,1});
			if(j+1<E[cur].size()) FORR(c,C[E[cur][j]][K-i-1]) E2[id+j+1].push_back({c,0});
			if(j) E2[id+j].push_back({id+j-1,0});
		}
		id+=E[cur].size();
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			E[i].clear();
			FOR(j,21) C[i][j].clear();
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		id=N;
		dfs(0,0);
		FOR(i,id) dp[i]=1<<30;
		deque<int> Q;
		dp[0]=0;
		Q.push_back(0);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop_front();
			FORR2(e,c,E2[cur]) {
				if(c==0&&chmin(dp[e],dp[cur])) Q.push_front(e);
				if(c==1&&chmin(dp[e],dp[cur]+1)) Q.push_back(e);
			}
		}
		for(i=1;i<N;i++) {
			if(dp[i]>=1<<20) dp[i]=-1;
			cout<<dp[i]<<" ";
		}
		cout<<endl;
		
		FOR(i,id) E2[i].clear();
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
