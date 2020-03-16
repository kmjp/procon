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

class SCC {
public:
	static const int MV = 210000;
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

int N;
int A[101010];
int C[101010];
SCC scc;
vector<pair<int,int>> RE[101010];
int mi[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	scc.init(N);
	FOR(i,N) {
		cin>>A[i]>>C[i];
		A[i]--;
		scc.add_edge(i,A[i]);
		RE[A[i]].push_back({C[i],i});
		
	}
	
	scc.scc();
	if(scc.SC.size()==1) {
		cout<<0<<endl;
		return;
	}
	
	FOR(i,N) mi[i]=1<<30;
	
	ll sum=0;
	FOR(i,N) if(RE[i].size()) {
		sort(ALL(RE[i]));
		FOR(j,RE[i].size()-1) sum+=RE[i][j].first;
		FOR(j,RE[i].size()) if(scc.GR[i]==scc.GR[RE[i][j].second]) {
			if(j==RE[i].size()-1) {
				if(j) {
					mi[scc.GR[i]]=min(mi[scc.GR[i]],RE[i][j].first-RE[i][j-1].first);
				}
				else {
					mi[scc.GR[i]]=min(mi[scc.GR[i]],RE[i][j].first);
				}
			}
			else {
				mi[scc.GR[i]]=min(mi[scc.GR[i]],0);
			}
			
		}
	}
	
	FOR(i,scc.SC.size()) if(scc.SC[i].size()>1) sum+=mi[i];
	
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
