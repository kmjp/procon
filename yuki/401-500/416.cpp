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

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<500000> uf;

int N,M,Q;
int R[101010];
int X[201010],Y[202020];
set<pair<int,int>> E;

vector<int> V[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>x>>y;
		E.insert({x-1,y-1});
	}
	FOR(i,Q) {
		cin>>X[i]>>Y[i];
		X[i]--,Y[i]--;
		E.erase({X[i],Y[i]});
	}
	
	FORR(r,E) uf(r.first,r.second);
	FOR(i,N) V[uf[i]].push_back(i);
	FOR(i,N) if(uf[0]==uf[i]) R[i]=-1;
	
	for(i=Q-1;i>=0;i--) if(uf[X[i]] != uf[Y[i]]) {
		x=uf[X[i]];
		y=uf[Y[i]];
		if(x==uf[0]) FORR(r,V[y]) R[r]=i+1;
		if(y==uf[0]) FORR(r,V[x]) R[r]=i+1;
		
		if(V[x].size()<V[y].size()) swap(x,y);
		FORR(r,V[y]) V[x].push_back(r);
		V[y].clear();
		uf(x,y);
		if(uf[x]==y) swap(V[x],V[y]);
		
	}
	FOR(i,N-1) cout<<R[i+1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
