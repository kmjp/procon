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

int N,MM;
int A[101010];
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
multiset<int> M[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>MM;
	FOR(i,N) cin>>A[i];
	
	FOR(i,MM) {
		cin>>x>>y;
		uf(x,y);
	}
	FOR(i,N) M[uf[i]].insert(A[i]);
	
	int comp=0;
	ll tot=0;
	vector<int> V;
	
	FOR(i,N) if(uf[i]==i) {
		comp++;
		tot+=*M[i].begin();
		M[i].erase(M[i].begin());
		FORR(r,M[i]) V.push_back(r);
	}
	
	if(comp==1) return _P("0\n");
	
	if(comp+V.size()<2*(comp-1)) return _P("Impossible\n");
	sort(ALL(V));
	FOR(i,V.size()) {
		if(comp+(i+1)<=2*(comp-1)) tot+=V[i];
	}
	
	cout<<tot<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
