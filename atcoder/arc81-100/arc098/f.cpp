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

int N,M;
ll A[101010],B[101010];
pair<ll,int> C[101010];
vector<int> E[101010];
ll BS[101010];
ll Q[101010];
int did[101010];
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		C[i]={max(A[i]-B[i],0LL),i};
		BS[i]=B[i];
	}
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	sort(C,C+N);
	FOR(i,N) {
		x=C[i].second;
		did[x]=1;
		vector<int> V;
		FORR(e,E[x]) if(did[e]==1) V.push_back(uf[e]);
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		
		ll BSS=BS[x];
		FORR(e,V) BSS+=BS[e];
		
		Q[x]=C[i].first+BSS;
		FORR(e,V) Q[x]=min(Q[x],max(Q[e],C[i].first)+BSS-BS[e]);
		FORR(e,V) uf(e,x);
		Q[uf[x]]=Q[x];
		BS[uf[x]]=BSS;
		
	}
	cout<<Q[uf[0]]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
