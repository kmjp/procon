#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class SCC {
public:
	static const int MV = 105000;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};

int M,N;
ll R[2][101010];
ll G[101010],G2[101010],hasinf[101010];
ll mo=1000000007;
SCC scc;
int GRm[101010];
vector<int> E[101010];
int in[101010];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>M;
	scc.init(M);
	FOR(i,M) {
		cin>>R[0][i]>>R[1][i];
		R[0][i]--;
		R[1][i]--;
		scc.add_edge(i,R[0][i]);
		scc.add_edge(i,R[1][i]);
		E[i].clear();
	}
	FOR(i,M) cin>>G[i];
	
	scc.scc();
	ZERO(GRm);
	ZERO(G2);
	ZERO(hasinf);
	ZERO(in);
	N=scc.SC.size();
	FOR(i,M) {
		if(scc.GR[i]==scc.GR[R[0][i]] && scc.GR[i]==scc.GR[R[1][i]]) GRm[scc.GR[i]]|=2;
		if(scc.GR[i]==scc.GR[R[0][i]] || scc.GR[i]==scc.GR[R[1][i]]) GRm[scc.GR[i]]|=1;
		if(scc.GR[i]!=scc.GR[R[0][i]]) E[scc.GR[i]].push_back(scc.GR[R[0][i]]), in[scc.GR[R[0][i]]]++;
		if(scc.GR[i]!=scc.GR[R[1][i]]) E[scc.GR[i]].push_back(scc.GR[R[1][i]]), in[scc.GR[R[1][i]]]++;
		G2[scc.GR[i]]+=G[i];
	}
	
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		
		if(G2[x] && (GRm[x]&2)) hasinf[x]=1;
		if(G2[x]) {
			G2[x]%=mo;
			if(G2[x]==0) G2[x]=mo;
		}
		if(scc.GR[0]==x) break;
		if(G2[x]!=0 && (GRm[x]&1)) hasinf[x]=1;
		
		
		FORR(e,E[x]) {
			hasinf[e]|=hasinf[x];
			G2[e]+=G2[x];
			if(--in[e]==0) Q.push(e);
		}
	}
	
	
	if(hasinf[scc.GR[0]]) {
		_P("Case #%d: UNBOUNDED\n",_loop);
	}
	else {
		_P("Case #%d: %lld\n",_loop,G2[scc.GR[0]]%mo);
	}
}

void init() {
	
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		//fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


