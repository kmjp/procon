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

int N,M,Q;
vector<int> E[1010];
int vis[1010];
int num;

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

void dfs(int cur,int tar) {
	if(vis[cur]) return;
	if(cur==tar) {
		num++;
		return;
	}
	vis[cur]=1;
	FORR(e,E[cur]) {
		if(num>=2) return;
		dfs(e,tar);
	}
	vis[cur]=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
		uf(x,y);
	}
	
	while(Q--) {
		ZERO(vis);
		num=0;
		cin>>x>>y;
		
		if(uf[x]!=uf[y]) {
			cout<<0<<endl;
			continue;
		}
		
		dfs(x,y);
		
		if(num==1) cout<<1<<endl;
		else cout<<0<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
