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

const int MV = 1<<22;

class SCC {
public:
	
	vector<vector<int> > SC; int NV,GR[MV],rev[MV];
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu); rev[cu]=ind;
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			revdfs(NUM[i],c);  c++;
		}
	}
};

int N,NV;
int L[505050],R[505050];
int CV[505050];

SCC sc;
void add(int c,int x,int y,int l=0,int r=1<<16,int k=1) { // x<=i<y
	if(x>=y) return;
	if(r<=x || y<=l) return;
	if(x<=l && r<=y) {
		sc.add_edge(c,CV[k]);
	}
	else {
		add(c,x,y,l,(l+r)/2,k*2);
		add(c,x,y,(l+r)/2,r,k*2+1);
	}
}

set<int> E[MV];
int num[MV];
int ma[MV];
int in[MV];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i];
	FOR(i,N) cin>>R[i];

	vector<pair<int,int>> V,V2;
	sc.init(MV);
	NV=N;
	FOR(i,N) {
		V.push_back({L[i]-i,i});
		V.push_back({R[i]-i,i+N});
		V2.push_back({L[i]+i,i});
		V2.push_back({R[i]+i,i+N});
	}

	sort(ALL(V));
	FOR(i,1<<16) CV[(1<<16)+i]=NV++;
	for(i=(1<<16)-1;i>=1;i--) {
		CV[i]=NV++;
		sc.add_edge(CV[i],CV[2*i]);
		sc.add_edge(CV[i],CV[2*i+1]);
	}
	FORR(e,V) {
		if(e.second<N) {
			x = e.second+(1<<16);
			CV[x]=NV++;
			sc.add_edge(CV[x],e.second);
			while(x>1) {
				x/=2;
				CV[x]=NV++;
				sc.add_edge(CV[x],CV[x*2]);
				sc.add_edge(CV[x],CV[x*2+1]);
			}
		}
		else add(e.second-N,0,e.second-N);
	}
	sort(ALL(V2));
	FOR(i,1<<16) CV[(1<<16)+i]=NV++;
	for(i=(1<<16)-1;i>=1;i--) {
		CV[i]=NV++;
		sc.add_edge(CV[i],CV[2*i]);
		sc.add_edge(CV[i],CV[2*i+1]);
	}
	x=0;
	FORR(e,V2) {
		if(e.second<N) {
			x = e.second+(1<<16);
			CV[x]=NV++;
			sc.add_edge(CV[x],e.second);
			while(x>1) {
				x/=2;
				CV[x]=NV++;
				sc.add_edge(CV[x],CV[x*2]);
				sc.add_edge(CV[x],CV[x*2+1]);
			}
		}
		else add(e.second-N,e.second-N+1,N);
	}
	sc.NV=NV;
	sc.scc();
	FOR(i,NV) {
		if(i<N) num[sc.GR[i]]++;
		FORR(e,sc.E[i]) if(sc.GR[i]!=sc.GR[e]) E[sc.GR[i]].insert(sc.GR[e]);
	}
	N=sc.SC.size();
	FOR(i,N) FORR(e,E[i]) in[e]++;
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		ma[x]+=num[x];
		FORR(e,E[x]) {
			ma[e]=max(ma[e],ma[x]);
			in[e]--;
			if(in[e]==0) Q.push(e);
		}
	}
	
	cout<<*max_element(ma,ma+N)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
