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
vector<int> G[2020202];
vector<int> GI[2020202];
int did[101010];
vector<int> E[1010101];
int id;
int dist[1010101];
int distg[1010101];

void dfs(int cur,int x) {
	if(did[cur]==x) return;
	did[cur]=x;
	G[id].push_back(cur);
	GI[cur].push_back(id);
	FORR(r,E[cur]) dfs(r,x);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		EE[r].push_back({x-1,y-1});
	}
	MINUS(did);
	FOR(i,1010100) if(EE[i].size()) {
		vector<int> V;
		FORR(e,EE[i]) {
			E[e.first].push_back(e.second);
			E[e.second].push_back(e.first);
			V.push_back(e.first);
			V.push_back(e.second);
		}
		
		FORR(r,V) if(did[r]!=i) {
			dfs(r,i);
			id++;
		}
		FORR(e,EE[i]) {
			E[e.first].clear();
			E[e.second].clear();
		}
	}
	
	memset(dist,0x3f,sizeof(dist));
	memset(distg,0x3f,sizeof(dist));
	dist[0]=0;
	vector<int> V;
	V.push_back(0);
	
	FOR(i,1010101) {
		if(V.empty()) break;
		vector<int> V2;
		FORR(r,V) FORR(gi,GI[r]){
			if(distg[gi]>i) {
				distg[gi]=i;
				FORR(g,G[gi]) V2.push_back(g);
			}
		}
		sort(ALL(V2));
		V2.erase(unique(ALL(V2)),V2.end());
		V.clear();
		FORR(r,V2) if(dist[r]>i+1) dist[r]=i+1, V.push_back(r);
	}
	
	if(dist[N-1]>0x3f0000) dist[N-1]=-1;
	cout<<dist[N-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
