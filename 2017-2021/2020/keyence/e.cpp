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
ll D[202020];
pair<int,int> P[202020];
vector<pair<int,int>> E[101010];
int ret[202020],fix[101010];
string S;

void dfs(int cur,int pre,int i) {
	if(i) S[cur]='B';
	else S[cur]='W';
	FORR(e,E[cur]) if(e.first!=pre && ret[e.second]<1<<30) dfs(e.first,cur,i^1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>D[i];
		P[i]={D[i],i};
	}
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back({y-1,i});
		E[y-1].push_back({x-1,i});
		ret[i]=1<<30;
	}
	sort(P,P+N);
	FOR(i,N) {
		x=P[i].second;
		FORR(e,E[x]) if(uf[e.first]!=uf[x] && (D[e.first]==D[x] || (D[e.first]<D[x]&&fix[e.first]))) {
			ret[e.second]=D[x];
			if(D[e.first]==D[x]) fix[e.first]=1;
			fix[x]=1;
			uf(x,e.first);
		}
	}
	
	int num=0;
	FOR(i,N) if(uf[i]==i) num++;
	if(num>1) return _P("-1\n");
	
	S.resize(N);
	dfs(0,0,0);
	
	cout<<S<<endl;
	FOR(i,M) {
		if(ret[i]==1<<30) ret[i]=1000000000;
		cout<<ret[i]<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
