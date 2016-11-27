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
int A[404040],B[404040];
ll C[404040];
vector<pair<int,int>> E[4040];
int Q;
ll D[4040][4040];

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

void dfs(int st,int cur,int pre,int ma) {
	D[st][cur]=ma;
	FORR(e,E[cur]) if(e.first != pre) {
		dfs(st,e.first,cur,max(ma,e.second));
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	priority_queue<pair<int,int>> EE;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i], A[i]--, B[i]--;
		EE.push({-C[i],i});
	}
	
	ll tot=0;
	while(EE.size()) {
		auto e=EE.top();
		x = A[e.second];
		y = B[e.second];
		EE.pop();
		if(uf[x]!=uf[y]) {
			uf(x,y);
			E[x].push_back({y,-e.first});
			E[y].push_back({x,-e.first});
			tot+=-e.first;
		}
	}
	
	FOR(i,N) dfs(i,i,-1,0);
	
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		cout<<tot-D[x-1][y-1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
