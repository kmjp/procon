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

int H,W;
int A[2020],B[2020],OA[2020],OB[2020];
int K;
int Y[16],X[16];
int R[2020][2020];
string S[2020];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 4200;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	void add_edge(int x,int y,V cap,V cap2) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,cap2});
	}
	void bfs(int cur) {
		MINUS(lev);
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			ITR(e,E[v]) if(e->cap>0 && lev[e->to]<0) lev[e->to]=lev[v]+1, q.push(e->to);
		}
	}
	V dfs(int from,int to,V cf) {
		if(from==to) return cf;
		for(;itr[from]<E[from].size();itr[from]++) {
			edge* e=&E[from][itr[from]];
			if(e->cap>0 && lev[from]<lev[e->to]) {
				V f=dfs(e->to,to,min(cf,e->cap));
				if(f>0) {
					e->cap-=f;
					E[e->to][e->reve].cap += f;
					return f;
				}
			}
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			bfs(from);
			if(lev[to]<0) return fl;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
	}
};
MaxFlow_dinic<int> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	vector<pair<int,int>> V;
	FOR(y,H) {
		cin>>A[y];
		OA[y]=A[y];
	}
	
	priority_queue<pair<int,int>> Q;
	FOR(x,W) {
		cin>>B[x];
		OB[x]=B[x];
		if(B[x]) Q.push({B[x],x});
	}
	
	FOR(y,H) {
		if(A[y]>Q.size()) return _P(":(\n");
		vector<int> V;
		FOR(x,A[y]) {
			i=Q.top().second;
			Q.pop();
			B[i]--;
			R[y][i]=1;
			V.push_back(i);
		}
		A[y]=0;
		FORR(v,V) if(B[v]) Q.push({B[v],v});
	}
	if(Q.size()) return _P(":(\n");

	FOR(y,H) S[y]=string(W,'.');
	
	int add=0;
	cin>>K;
	FOR(i,K) {
		cin>>Y[i]>>X[i];
		Y[i]--,X[i]--;
		if(R[Y[i]][X[i]]) {
			A[Y[i]]++;
			B[X[i]]++;
			add++;
		}
		R[Y[i]][X[i]]=-1;
		S[Y[i]][X[i]]='x';
	}
	
	FOR(y,H) {
		mf.add_edge(4010,y,A[y],OA[y]-A[y]);
		FOR(x,W) {
			if(R[y][x]==0) mf.add_edge(y,2000+x,1,0);
			else if(R[y][x]==1) mf.add_edge(y,2000+x,0,1);
		}
	}
	FOR(x,W) {
		mf.add_edge(2000+x,4011,B[x],OB[x]-B[x]);
	}
	
	if(mf.maxflow(4010,4011)!=add) return _P(":(\n");
	
	cout<<"Yay!"<<endl;
	FOR(y,H) {
		FORR(e,mf.E[y]) if(e.to>=2000 && e.to<4000 && e.cap==0) S[y][e.to-2000]='o';
		cout<<S[y]<<endl;
	}
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
