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
int A[101010],B[101010];
int C[101010];
int L[202020],R[202020];

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
vector<pair<int,int>> E[202020];
vector<int> ret;

void dfs(int cur,int pre) {
	FORR(e,E[cur]) if(e.first!=pre) {
		dfs(e.first,cur);
		if(C[e.first]) {
			ret.push_back(e.second);
			C[e.first]^=1;
			C[cur]^=1;
		}
	}

}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<int> Xs;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		Xs.push_back(A[i]);
	}
	Xs.push_back(1<<30);
	sort(ALL(Xs));
	FOR(i,N) {
		x=lower_bound(ALL(Xs),A[i])-Xs.begin();
		C[x]=B[i];
	}
	for(i=N;i>=1;i--) C[i]^=C[i-1];
	
	
	FOR(i,M) {
		cin>>L[i]>>R[i];
		L[i]=lower_bound(ALL(Xs),L[i])-Xs.begin();
		R[i]=lower_bound(ALL(Xs),R[i]+1)-Xs.begin();
		if(uf[L[i]]!=uf[R[i]]) {
			E[L[i]].push_back({R[i],i+1});
			E[R[i]].push_back({L[i],i+1});
			uf(L[i],R[i]);
		}
	}
	FOR(i,N+1) if(uf[i]==i) {
		dfs(i,i);
		if(C[i]) return _P("-1\n");
	}
	cout<<ret.size()<<endl;
	sort(ALL(ret));
	FORR(r,ret) cout<<r<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
