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
vector<pair<int,pair<int,int>>> E;

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

vector<ll> node[202020]; // num, leftid,leftcost,rightid,rightcose
int id[202020];
ll ret[101010];

void dfs(int cur,ll sum) {
	if(cur<N) {
		ret[cur]=sum;
	}
	else {
		dfs(node[cur][1],sum+node[cur][2]);
		dfs(node[cur][3],sum+node[cur][4]);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>j;
		E.push_back({j,{x-1,y-1}});
	}
	FOR(i,N) {
		id[i]=i;
		node[i]={1,-1,0,-1,0};
	}
	sort(ALL(E));
	reverse(ALL(E));
	int nex=N;
	FORR(e,E) {
		x=id[uf[e.second.first]];
		y=id[uf[e.second.second]];
		node[nex]={node[x][0]+node[y][0],x,node[y][0]*e.first,y,node[x][0]*e.first};
		uf(e.second.first,e.second.second);
		id[uf[e.second.first]]=nex++;
	}
	dfs(nex-1,0);
	FOR(i,N) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
