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

int N,M;
int U[2020],V[2020],W[2020],T[2020];
vector<pair<int,int>> E[2020];
int D[1010][1010];
ll X;
ll p2[2020];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,2010) p2[i+1]=p2[i]*2%mo;
	
	cin>>N>>M>>X;
	priority_queue<pair<int,int>> PQ;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		U[i]--;
		V[i]--;
		E[U[i]].push_back({V[i],i});
		E[V[i]].push_back({U[i],i});
		PQ.push({-W[i],i});
	}
	
	ll S=0;
	while(PQ.size()) {
		x=PQ.top().second;
		PQ.pop();
		if(uf[U[x]]!=uf[V[x]]) {
			S+=W[x];
			uf(U[x],V[x]);
			T[x]=1;
		}
	}
	FOR(i,N) {
		FOR(x,N) D[i][x]=1<<30;
		D[i][i]=0;
		priority_queue<pair<int,int>> Q;
		Q.push({0,i});
		while(Q.size()) {
			int co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(D[i][cur]!=co) continue;
			FORR(e,E[cur]) {
				if(D[i][e.first]>max(co,W[e.second])) {
					D[i][e.first]=max(co,W[e.second]);
					Q.push({-D[i][e.first],e.first});
				}
			}
		}
	}
	
	ll DD=X-S;
	
	int eq=0,up=0;
	FOR(i,M) if(T[i]==0) {
		if(W[i]-D[U[i]][V[i]]==DD) eq++;
		if(W[i]-D[U[i]][V[i]]>DD) up++;
	}
	ll ret=0;
	if(DD>0) {
		ret=2*(p2[eq]+mo-1)*p2[up]%mo;
	}
	else if(DD==0) {
		ret=2*(p2[eq]+mo-1)*p2[up]%mo;
		ret+=(p2[N-1]+mo-2)*p2[M-N+1]%mo;
	}

	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
