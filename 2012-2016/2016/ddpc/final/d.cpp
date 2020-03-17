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
int mat[202][202];
int NO;
int parity[202];


class SCC {
public:
	static const int MV = 202;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<NV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0,i; SC.clear(); SC.resize(NV); NUM.clear();
		assert(NV);
		FOR(i,NV) vis[i]=0; FOR(i,NV) if(!vis[i]) dfs(i); FOR(i,NV) vis[i]=0;
		for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};
SCC scc;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(mat);
	cin>>N>>M;
	scc.init(N);
	FOR(i,M) {
		cin>>x>>y>>s;
		x--,y--;
		scc.add_edge(x,y);
		mat[x][y]=s=="O";
		if(s=="O") {
			parity[x]^=1;
			parity[y]^=1;
			NO++;
		}
	}
	
	if(NO==0) return _P("%d\n",N);
	
	scc.scc();
	
	int op=0;
	FOR(i,N) op+=parity[i];
	int M=scc.SC.size();
	
	if(op==0) {
		int numcount[202]={};
		FOR(x,N) FOR(y,N) if(mat[x][y]==1) {
			if(scc.GR[x]!=scc.GR[y]) return _P("0\n");
			numcount[scc.GR[x]]++;
		}
		FOR(i,M) if(numcount[i]==NO) {
			x=scc.SC[i].size();
			cout<<x<<endl;
			return;
		}
		
	}
	else if(op==2) {
		int in[202]={};
		int num[202]={};
		int must[202];
		vector<int> E[202];
		
		FOR(x,N) FOR(y,N) {
			if(scc.GR[x]==scc.GR[y]) {
				if(mat[x][y]==1) {
					must[scc.GR[x]]++;
					if(must[scc.GR[x]]==NO) return _P("2\n");
				}
			}
			else {
				if(mat[x][y]==1) {
					E[scc.GR[x]].push_back(scc.GR[y]);
					in[scc.GR[y]]++;
				}
			}
		}
		queue<int> Q;
		FOR(i,M) if(in[i]==0) Q.push(i);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			num[x]+=must[x];
			if(num[x]==NO) return _P("1\n");
			FORR(e,E[x]) {
				num[e]=max(num[e],num[x]+1);
				in[e]--;
				if(in[e]==0) Q.push(e);
			}
		}
	}
	cout<<0<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
