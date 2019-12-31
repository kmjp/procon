#include <bits/stdc++.h>
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

int N,Q;
int A[101010];
int B[101010];
int C[101010];
int X[101010],V[101010],W[101010],LC[101010];
int OL[101010],OR[101010],eid;
int P[21][100005],D[100005];

vector<int> E[101010];
vector<int> QS[101010],QL[101010],QE[101010];
vector<int> DV[101010];
set<pair<int,int>> S[101010];
int nt[101010],nt2[101010];
set<pair<int,int> > SV;

void dfs(int cur) {
	OL[cur]=eid++;
	nt[cur]=QE[cur].size();
	DV[D[cur]].push_back(cur);
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it), nt[cur]+=nt[*it];
	OR[cur]=eid;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void gomod(int r) {
	while(S[r].size()) {
		auto it=S[r].end();
		int q=(*--it).second;
		if(X[q]<A[r]) break;
		X[q] %= A[r];
		S[r].erase(it);
		S[r].insert({X[q],q});
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>B[i]>>C[i];
		E[B[i]-1].push_back(C[i]-1);
		E[C[i]-1].push_back(B[i]-1);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	FOR(i,Q) {
		cin>>X[i]>>V[i]>>W[i];
		V[i]--,W[i]--;
		LC[i]=lca(V[i],W[i]);
		QS[V[i]].push_back(i);
		QL[LC[i]].push_back(i);
		QE[W[i]].push_back(i);
		SV.insert({OL[W[i]],i});
	}
	for(i=N;i>=0;i--) FORR(r,DV[i]) {
		int mav=-1, tar=-1;
		FORR(e,E[r]) if(D[e]==D[r]+1 && (int)S[e].size()>mav) mav=S[e].size(),tar=e;
		if(mav>=0) {
			swap(S[r],S[tar]);
			FORR(e,E[r]) if(D[e]==D[r]+1 && e!=tar) {
				FORR(ss,S[e]) S[r].insert(ss);
				S[e].clear();
			}
		}
		FORR(q,QS[r]) S[r].insert({X[q],q});
		gomod(r);
		FORR(q,QL[r]) S[r].erase({X[q],q});
	}
	
	FOR(i,N+1) FORR(r,DV[i]) {
		FORR(q,QL[r]) S[r].insert({X[q],q});
		gomod(r);
		FORR(q,QE[r]) S[r].erase({X[q],q}),SV.erase({OL[W[q]],q});
		
		int mav=-1, tar=-1;
		FORR(e,E[r]) if(D[e]==D[r]+1 && nt[e]>mav) mav=nt[e],tar=e;
		
		FORR(e,E[r]) if(D[e]==D[r]+1 && tar!=e) {
			for(auto sit=SV.lower_bound({OL[e],0});sit!=SV.end() && sit->first<OR[e];sit++) {
				int ss=sit->second;
				if(S[r].count({X[ss],ss})) S[e].insert({X[ss],ss}), S[r].erase({X[ss],ss});
			}
		}
		if(tar!=-1) swap(S[tar],S[r]);
	}
	
	
	FOR(i,Q) _P("%d\n",X[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
