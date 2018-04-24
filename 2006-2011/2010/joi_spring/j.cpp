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

template<class V> class MaxFlow_Ford {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 100000;
	vector<edge> E[MV];
	int vis[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	V dfs(int from,int to,V cf) {
		V tf;
		if(from==to) return cf;
		vis[from]=1;
		FORR(e,E[from]) if(vis[e.to]==0 && e.cap>0 && (tf = dfs(e.to,to,min(cf,e.cap)))>0) {
			e.cap -= tf;
			E[e.to][e.reve].cap += tf;
			return tf;
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			ZERO(vis);
			if((tf = dfs(from,to,numeric_limits<V>::max()))==0) return fl;
			fl+=tf;
		}
	}
};
MaxFlow_Ford<int> mf;

int N;
int U[303];
int D[303];
int L[303];
int R[303];
int A[303][303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>U[i];
	FOR(i,N) cin>>D[i];
	FOR(i,N) cin>>L[i];
	FOR(i,N) cin>>R[i];
	
	int tot=0;
	FOR(x,N) mf.add_edge(0,2+x,U[x]+D[x]), tot+=U[x]+D[x];
	FOR(y,N) mf.add_edge(302+y,1,N-(L[y]+R[y]));
	FOR(x,N) FOR(y,N) mf.add_edge(2+x,302+y,1);
	
	if(mf.maxflow(0,1)!=tot) return _P("NO\n");
	
	FOR(x,N) FOR(y,N) {
		if(mf.E[2+x][y+1].cap==1) A[y][x]=2;
		if(A[y][x]==0) {
			if(U[x]==0) A[y][x]=1;
			U[x]--;
		}
		if(A[y][x]==2) {
			if(L[y]==0) A[y][x]=3;
			L[y]--;
		}
	}
	FOR(y,N) {
		string S="^v<>";
		FOR(x,N) cout<<S[A[y][x]];
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
