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
vector<int> E[202020];
vector<int> D[2];
int G[202020];
int dep[202020],from[202020];
int ret[202020];

int dfs(int cur,int pre) {
	FORR(e,E[cur]) if(e!=pre) G[cur]|=dfs(e,cur);
	return G[cur];
}

pair<int,int> farthest(int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre&&G[e]) r=max(r, farthest(e,cur,d+1,D));
	return r;
}

//—¼’[‚ÆŠÔ‚Ì’¸“_‚ð•Ô‚·
vector<pair<int,int>> diameter(int root) { // diameter,center
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(root,root,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	farthest(v2.second,v2.second,0,D[1]);
	
	vector<pair<int,int>> R;
	for(int i=N-1;i>=0;i--) if(D[0][i]+D[1][i]==v2.first) R.push_back({D[0][i],i});
	sort(ALL(R));

	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,K) {
		cin>>x;
		G[x-1]=1;
	}
	int root;
	FOR(i,N) if(G[i]==1) root=i;
	dfs(root,root);
	
	queue<int> Q;
	FOR(i,N) {
		if(G[i]==1) from[i]=i, Q.push(i);
		else dep[i]=1<<20;
	}
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR(e,E[cur]) if(dep[e]>dep[cur]+1) {
			dep[e]=dep[cur]+1;
			from[e]=from[cur];
			Q.push(e);
		}
	}
	
	auto v=diameter(root);
	int len=0;
	FOR(i,N) if(G[i]) FORR(e,E[i]) len+=G[e];
	FOR(i,N) if(G[i]) {
		ret[i]=len-max(D[0][i],D[1][i]);
	}
	FOR(i,N) {
		if(G[i]==0) ret[i]=dep[i]+ret[from[i]];
		cout<<ret[i]<<endl;
	}
	
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
