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

int N,M,K;

template<int um> class UF_pop {
	public:
	vector<int> par,rank; vector<vector<int>> hist;
	UF_pop() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; hist.clear(); FOR(i,um) rank[i]=0,par[i]=i;}
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
UF_pop<404040> uf;

int U[404040],V[404040];
int S[404040];
int Q;
int A[404040],B[404040];
int ret[404040];
map<pair<int,int>,vector<int>> qs;
map<pair<int,int>,vector<int>> es;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
	}
	FOR(i,N) cin>>S[i];
	FOR(i,M) {
		if(S[U[i]]==S[V[i]]) {
			uf(U[i],V[i]);
		}
		else {
			es[{S[U[i]],S[V[i]]}].push_back(i);
			es[{S[V[i]],S[U[i]]}].push_back(i);
		}
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
		qs[{S[A[i]],S[B[i]]}].push_back(i);
	}
	
	FORR2(s,tq,qs) {
		FORR(e,es[s]) uf(U[e],V[e]);
		FORR(q,tq) ret[q]=uf[A[q]]==uf[B[q]];
		FORR(e,es[s]) uf.pop();
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
