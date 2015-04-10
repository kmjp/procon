#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

int N,M;

ll p2[505050];
int odd[505050];
vector<pair<int,int> > E[505000];
ll mo=1000000007;
ll ret;

ll dfs(int cur,int pre) {
	ll ret=0;
	FORR(r,E[cur]) if(r.first!=pre) {
		ret += dfs(r.first,cur);
		if(odd[r.first]==0) ret += r.second;
		odd[cur]^=odd[r.first];
	}
	return ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	UF<500000> uf;
	
	cin>>N>>M;
	
	p2[0]=1;
	FOR(i,M) {
		p2[i+1]=p2[i]*2%mo;
		cin>>x>>y;
		x--,y--;
		ret = (ret+p2[i+1])%mo;
		if(uf[x]==uf[y]) {
			odd[x]^=1;
			odd[y]^=1;
		}
		else {
			uf(x,y);
			E[x].emplace_back(y,p2[i+1]);
			E[y].emplace_back(x,p2[i+1]);
		}
	}
	cout<<(ret+dfs(0,-1))%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
