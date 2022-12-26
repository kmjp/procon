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

int N,M,K;
int A[101010],B[101010],C[101010];
vector<int> Cs[101010];

template<int um> class UF_pop {
	public:
	vector<int> par,rank; vector<vector<int>> hist;
	UF_pop() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):operator[](par[x]);}
	void pop() {
		if(hist.size()) {
			auto a=hist.back();
			hist.pop_back();
			par[a[0]]=a[1]; rank[a[0]]=a[2];
			par[a[3]]=a[4]; rank[a[3]]=a[5];
		}
	}
	void operator()(int x,int y) {
		x=operator[](x); y=operator[](y);
		hist.push_back({x,par[x],rank[x],y,par[y],rank[y]});
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else rank[x]+=(rank[x]==rank[y]), par[y]=x;
	}
};
UF_pop<101010> uf;
int dist[101010];

set<int> cand[101010];

vector<int> V[202020];

vector<int> D[202020];
int did[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--;
		B[i]--;
		C[i]--;
		Cs[C[i]].push_back(i);
	}
	int id=0;
	FOR(i,101010) if(Cs[i].size()) {
		FORR(c,Cs[i]) {
			uf(A[c],B[c]);
		}
		FORR(c,Cs[i]) {
			if(did[A[c]]==0) {
				did[A[c]]=1;
				D[uf[A[c]]].push_back(A[c]);
			}
			if(did[B[c]]==0) {
				did[B[c]]=1;
				D[uf[B[c]]].push_back(B[c]);
			}
		}
		FORR(c,Cs[i]) {
			did[A[c]]=did[B[c]]=0;
			if(D[A[c]].size()) {
				swap(V[id],D[A[c]]);
				FORR(v,V[id]) cand[v].insert(id);
				id++;
			}
			if(D[B[c]].size()) {
				swap(V[id],D[B[c]]);
				FORR(v,V[id]) cand[v].insert(id);
				id++;
			}
			uf.pop();
		}
	}
	
	
	queue<int> Q;
	FOR(i,N) dist[i]=202020;
	dist[0]=0;
	Q.push(0);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR(c,cand[cur]) {
			FORR(v,V[c]) if(v!=cur) {
				if(dist[v]>dist[cur]+1) {
					dist[v]=dist[cur]+1;
					Q.push(v);
				}
				cand[v].erase(c);
			}
		}
		cand[cur].clear();
	}
	
	if(dist[N-1]==202020) cout<<-1<<endl;
	else cout<<dist[N-1]*K<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
