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
vector<int> E[101010];
vector<int> G[101010];
int vis[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		uf(x-1,y-1);
	}
	FOR(i,N) G[uf[i]].push_back(i);
	
	ll ret=0;
	FOR(i,N) if(uf[i]==i) {
		queue<int> Q;
		FORR(g,G[i]) if(E[g].size()>=2) {
			FORR(e,E[g]) vis[e]=1, Q.push(e);
		}
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(e,E[x]) if(vis[e]==0) vis[e]=1, Q.push(e);
		}
		int num=0;
		FORR(g,G[i]) num+=vis[g];
		ret+=1LL*num*(num-1);
		FORR(g,G[i]) if(vis[g]==0) ret+=E[g].size();
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
