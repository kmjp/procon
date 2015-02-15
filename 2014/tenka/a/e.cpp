#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;
 
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
 
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------
 
int H,W,N;
string S[20001];
int G[20001][16];
const int MV = 20000*16;
int NN[MV];
int D[MV][16];
vector<int> E[MV], RE[MV], NUM;
vector<vector<int> > SC;
int vis[MV],GR[MV];
map<int,int> UF;

vector<int> OUT[MV];
int IN[MV];

class SCC {
public:
	int NV;
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear(); }}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){ SC[c].clear(); revdfs(NUM[i],c++);}
		SC.resize(c);
	}
};

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>H>>W;
	FOR(i,H) cin>>S[i];
	MINUS(G);
	FOR(i,H*W) FOR(j,16) D[i][j]=H;

	FOR(y,H) FOR(x,W) if(G[y][x]==-1) {
		queue<int> Q;
		Q.push(y*100+x);
		G[y][x]=N;
		while(!Q.empty()) {
			f=Q.front();
			Q.pop();
			int cy=f/100,cx=f%100;
			FOR(i,4) {
				int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
				int ty=cy+dy[i],tx=cx+dx[i];
				if(tx<0 || tx>=W || ty<0 || ty>=H || G[ty][tx]>=0) continue;
				if(S[cy][cx]==S[ty][tx]) G[ty][tx]=N,Q.push(ty*100+tx);
			}
		}
		N++;
	}
	
	SCC gr;
	gr.init(N);
	for(y=1;y<H;y++) FOR(x,W) if(G[y][x]!=G[y-1][x]) gr.add_edge(G[y][x],G[y-1][x]);
	gr.scc();
	FOR(i,SC.size()) FOR(j,SC[i].size()) UF[SC[i][j]]=SC[i][0];
	
	FOR(y,H) FOR(x,W) {
		G[y][x]=UF[G[y][x]];
		D[G[y][x]][x]=min(D[G[y][x]][x],y);
		if(y>0 && G[y][x]!=G[y-1][x]) OUT[G[y][x]].push_back(G[y-1][x]);
	}
	FOR(i,N) if(UF[i]==i) FOR(j,OUT[i].size()) IN[OUT[i][j]]++;
	queue<int> Q;
	FOR(i,N) if(UF[i]==i && IN[i]==0) Q.push(i);
	while(!Q.empty()) {
		int cur=Q.front();
		Q.pop();
		FOR(x,W) NN[cur]+=H-D[cur][x];
		FOR(i,OUT[cur].size()) {
			int tar=OUT[cur][i];
			FOR(x,W) D[tar][x]=min(D[tar][x],D[cur][x]);
			if(--IN[tar]==0) Q.push(tar);
		}
	}
	cin>>i;
	while(i--) {
		cin>>x>>y;
		cout<<NN[G[y-1][x-1]]<<endl;
	}
	
	
}
int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}
