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



int P[21][200005],D[200005];
int N,M,Q;
vector<int> E[101010];
int U[101010],V[101010];
int C[101010];
ll SL[101010];
ll ret=0,mi;

void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}
int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]];  // dist
}

void dfs2(int cur,int pre) {
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur);
		C[cur]+=C[e];
		SL[cur]+=SL[e]+C[e];
	}
}
void dfs3(int cur,int pre,int pc,ll psl) {
	mi=min(mi,SL[cur]+psl);
	FORR(e,E[cur]) if(e!=pre) {
		dfs3(e,cur,pc+C[cur]-C[e],psl+SL[cur]-(SL[e]+C[e])+pc+C[cur]-C[e]);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		uf(x,y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	FOR(i,Q) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		if(uf[U[i]]!=uf[V[i]]) {
			C[U[i]]++;
			C[V[i]]++;
		}
	}
	
	FOR(i,N) if(uf[i]==i) {
		dfs2(i,i);
		mi=1LL<<60;
		dfs3(i,i,0,0);
		ret+=mi;
	}
	
	
	FOR(i,N) if(uf[i]==i) {
		E[N].push_back(i);
		E[i].push_back(N);
	}

	dfs(N);
	FOR(i,19) FOR(x,N+1) P[i+1][x]=P[i][P[i][x]];
	FOR(i,Q) if(uf[U[i]]==uf[V[i]]) ret+=dist(U[i],V[i]);
	cout<<ret<<endl;

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
