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

int N;
int P[202020],T[202020];
ll V0[202020],V1[202020];
ll ret;

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


pair<double,int> hoge(int v) {
	if(V0[v]==0) return {1e9,v};
	else return {1.0*V1[v]/V0[v],v};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<N;i++) {
		cin>>P[i];
		P[i]--;
	}
	
	set<pair<double,int>> S;
	FOR(i,N) {
		cin>>x;
		V0[i]=(x==0);
		V1[i]=(x==1);
		T[i]=i;
		if(i) S.insert(hoge(i));
	}
	
	while(S.size()) {
		int cur=S.begin()->second;
		S.erase(S.begin());
		
		int par=uf[P[cur]];
		if(T[par]) S.erase(hoge(par));
		ret+=V1[par]*V0[cur];
		V0[cur]=V0[par]=V0[cur]+V0[par];
		V1[cur]=V1[par]=V1[cur]+V1[par];
		T[cur]=T[par];
		P[cur]=P[par];
		uf(par,cur);
		if(T[uf[par]]) S.insert(hoge(uf[par]));
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
