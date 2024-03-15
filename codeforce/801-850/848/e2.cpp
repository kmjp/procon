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

int T;
int N;
vector<int> E[202020],LB[202020];
int A[202020];
int L[202020],R[202020];
vector<int> B[202020],P[202020];
vector<vector<int>> BL[202020];
vector<vector<int>> BR[202020];
int id;

void dfs(int cur,int pre) {
	L[cur]=id++;
	int i;
	FOR(i,E[cur].size()) {
		if(E[cur][i]==pre) {
			E[cur].erase(E[cur].begin()+i);
			break;
		}
	}
	BL[cur]={{}};
	BR[cur]={{}};
	LB[cur].clear();
	FORR(e,E[cur]) {
		dfs(e,cur);
		LB[cur].push_back(L[e]);
		BL[cur].push_back(BL[cur].back());
		FORR(b,B[e]) {
			int v=b;
			FORR(t,BL[cur].back()) v=min(v,t^v);
			if(v) BL[cur].back().push_back(v);
		}
	}
	R[cur]=id;
	reverse(ALL(E[cur]));
	FORR(e,E[cur]) {
		BR[cur].push_back(BR[cur].back());
		FORR(b,B[e]) {
			int v=b;
			FORR(t,BR[cur].back()) v=min(v,t^v);
			if(v) BR[cur].back().push_back(v);
		}
	}
	B[cur]=BL[cur].back();
	int v=A[cur];
	FORR(t,B[cur]) v=min(v,t^v);
	if(v) B[cur].push_back(v);
	
	reverse(ALL(E[cur]));
	reverse(ALL(BR[cur]));
}

vector<int> merge(vector<int> p2,int v,vector<int> A,vector<int> B) {
	FORR(p,p2) v=min(v,v^p);
	if(v) p2.push_back(v);
	FORR(b,A) {
		int v=b;
		FORR(p,p2) v=min(v,v^p);
		if(v) p2.push_back(v);
	}
	FORR(b,B) {
		int v=b;
		FORR(p,p2) v=min(v,v^p);
		if(v) p2.push_back(v);
	}
	return p2;
}

void dfs2(int cur,vector<int> par) {
	P[cur]=par;
	int i;
	FOR(i,E[cur].size()) {
		vector<int> p2=merge(par,A[cur],BL[cur][i],BR[cur][i+1]);
		dfs2(E[cur][i],p2);
	}
	
}

int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			E[i].clear();
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		id=0;
		dfs(0,0);
		dfs2(0,vector<int>());
		cin>>Q;
		while(Q--) {
			int root,V;
			cin>>root>>V;
			root--,V--;
			int ret=0;
			if(root==V) {
				vector<int> p2=merge(P[V],A[V],B[V],B[V]);
				FORR(b,p2) ret=max(ret,ret^b);
			}
			else if(L[root]<L[V]||L[root]>=R[V]) {
				FORR(b,B[V]) ret=max(ret,ret^b);
			}
			else {
				i=lower_bound(ALL(LB[V]),L[root]+1)-LB[V].begin()-1;
				vector<int> p2=merge(P[V],A[V],BL[V][i],BR[V][i+1]);
				FORR(b,p2) ret=max(ret,ret^b);
				
			}
			cout<<ret<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
