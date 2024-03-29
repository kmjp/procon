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


class SCC_BI {
public:
	static const int MV = 310000;
	int NV,time;
	vector<vector<int> > E;
	vector<int> ord,llink,inin;
	stack<int> roots,S;
	vector<int> M; //point to group
	vector<int> ART; // out
	vector<vector<int> > SC; // out
	vector<pair<int,int> > BR; // out
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { assert(NV); E[x].push_back(y); E[y].push_back(x); }
	void dfs(int cur,int pre) {
		int art=0,conn=0,i,se=0;
		ord[cur]=llink[cur]=++time;
		S.push(cur); inin[cur]=1; roots.push(cur);
		FOR(i,E[cur].size()) {
			int tar=E[cur][i];
			if(ord[tar]==0) {
				conn++; dfs(tar,cur);
				llink[cur]=min(llink[cur],llink[tar]);
				art += (pre!=-1 && ord[cur]<=llink[tar]);
				if(ord[cur]<llink[tar]) BR.push_back(make_pair(min(cur,tar),max(cur,tar)));
			}
			else if(tar!=pre || se) {
				llink[cur]=min(llink[cur],ord[tar]);
				while(inin[tar]&&ord[roots.top()]>ord[tar]) roots.pop();
			}
			else se++; // double edge
		}
		
		if(cur==roots.top()) {
			SC.push_back(vector<int>());
			while(1) {
				i=S.top(); S.pop(); inin[i]=0;
				SC.back().push_back(i);
				M[i]=SC.size()-1;
				if(i==cur) break;
			}
			sort(SC.back().begin(),SC.back().end());
			roots.pop();
		}
		if(art || (pre==-1&&conn>1)) ART.push_back(cur);
	}
	void scc() {
		SC.clear(),BR.clear(),ART.clear(),M.resize(NV);
		ord.clear(),llink.clear(),inin.clear(),time=0;
		ord.resize(NV);llink.resize(NV);inin.resize(NV);
		for(int i=0;i<NV;i++) if(!ord[i]) dfs(i,-1);
		sort(BR.begin(),BR.end()); sort(ART.begin(),ART.end());
	}
};

int N,M,K;
ll P;
int S[303030],G[303030],C[303030];
int U[303030],V[303030],W[303030];
SCC_BI scc;
vector<pair<int,int>> E[303030];
ll dp[303030];
int NSV[303030];

int dfs(int cur,int pre) {
	FORR(e,E[cur]) if(e.first!=pre) {
		NSV[cur]+=dfs(e.first,cur);
		
		if(NSV[e.first]==0 || NSV[e.first]==K) {
			dp[cur]+=dp[e.first];
		}
		else {
			dp[cur]+=max(0LL,dp[e.first]-e.second);
		}
	}
	return NSV[cur];
}

void dfs2(int cur,int pre,ll par) {
	if(pre!=-1) {
		if(NSV[cur]==0 || NSV[cur]==K) {
			dp[cur]+=par;
		}
		else {
			FORR(e,E[cur]) if(e.first==pre) dp[cur]+=max(0LL,par-e.second);
		}
	}
	
	FORR(e,E[cur]) if(e.first!=pre) {
		ll val;
		if(NSV[e.first]==0 || NSV[e.first]==K) {
			val=dp[cur]-dp[e.first];
		}
		else {
			val=dp[cur]-max(0LL,dp[e.first]-e.second);
		}
		dfs2(e.first,cur,val);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,K) {
		cin>>x;
		S[x-1]=1;
	}
	FOR(i,N) cin>>C[i];
	scc.init(N);
	FOR(i,M) cin>>W[i];
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
		scc.add_edge(U[i],V[i]);
	}
	scc.scc();
	FOR(i,scc.SC.size()) FORR(r,scc.SC[i]) G[r]=i;
	
	FOR(i,N) {
		NSV[G[i]]+=S[i];
		dp[G[i]]+=C[i];
	}
	FOR(i,M) {
		U[i]=G[U[i]];
		V[i]=G[V[i]];
		if(U[i]!=V[i]) {
			E[U[i]].push_back({V[i],W[i]});
			E[V[i]].push_back({U[i],W[i]});
		}
	}
	
	dfs(0,0);
	dfs2(0,-1,0);
	FOR(i,N) cout<<dp[G[i]]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
