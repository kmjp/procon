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
set<pair<int,int>> E[202020];
int ret[202020];
int vis[202020];

void dfs(int cur,int d) {
	if(cur==N-1) {
		ret[d]++;
		return;
	}
	vis[cur]=1;
	FORR2(e,c,E[cur]) if(vis[e]==0) dfs(e,c+d);
	vis[cur]=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert({y-1,1});
		E[y-1].insert({x-1,1});
	}
	queue<int> Q;
	FOR(i,N) if(i!=0&&i!=N-1&&E[i].size()==1) Q.push(i);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		int e=E[cur].begin()->first;
		E[cur].clear();
		E[e].erase({cur,1});
		if(E[e].size()==1) Q.push(e);
	}
	
	FOR(i,N) if(i!=0&&i!=N-1&&E[i].size()==2) {
		auto p1=*E[i].begin();
		auto p2=*next(E[i].begin());
		E[p1.first].erase({i,p1.second});
		E[p2.first].erase({i,p2.second});
		E[p1.first].insert({p2.first,p1.second+p2.second});
		E[p2.first].insert({p1.first,p1.second+p2.second});
	}
	
	dfs(0,0);
	
	for(i=1;i<=N-1;i++) cout<<ret[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
