#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
vector<pair<int,int>> EE[1010101];
int did[101010];
vector<int> TE[101010];

vector<int> E[301010];
int id=100001;
int dist[303030];

void dfs(int cur,int x) {
	if(did[cur]==x) return;
	did[cur]=x;
	E[id].push_back(cur);
	E[cur].push_back(id);
	FORR(r,TE[cur]) dfs(r,x);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		EE[r].push_back({x,y});
	}
	MINUS(did);
	FOR(i,1010100) if(EE[i].size()) {
		vector<int> V;
		FORR(e,EE[i]) {
			TE[e.first].push_back(e.second);
			TE[e.second].push_back(e.first);
			V.push_back(e.first);
			V.push_back(e.second);
		}
		
		FORR(r,V) if(did[r]!=i) {
			dfs(r,i);
			id++;
		}
		FORR(e,EE[i]) {
			TE[e.first].clear();
			TE[e.second].clear();
		}
	}
	
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	queue<int> Q;
	Q.push(1);
	while(Q.size()) {
		x = Q.front();
		Q.pop();
		FORR(e,E[x]) {
			if(dist[e]>dist[x]+1) {
				dist[e]=dist[x]+1;
				Q.push(e);
			}
		}
	}
	
	if(dist[N]>0x3f0000) dist[N]=-1;
	else dist[N]/=2;
	cout<<dist[N]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
