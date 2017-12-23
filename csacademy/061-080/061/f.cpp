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

template<int MV> class UndirectedEulerPath {
public:
	vector<int> path;
	multiset<int> E[MV];
	void add_path(int x,int y) { E[x].insert(y); E[y].insert(x); }
	
	void dfs(int cur) {
		while(E[cur].size()) {
			int tar=*E[cur].begin();
			E[cur].erase(E[cur].begin());
			E[tar].erase(E[tar].find(cur));
			dfs(tar);
		}
		path.push_back(cur);
	}
	
	bool GetPath() {
		int fo=-1,odd=0,i,np=0;
		FOR(i,MV) {
			np += E[i].size();
			if(E[i].size()%2) odd++, fo=(fo==-1)?i:fo;
		}
		if(odd!=0 && odd!=2) return false;
		dfs(odd?fo:0);
		reverse(path.begin(),path.end());
		return path.size()==np/2+1;
	}
};

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

UndirectedEulerPath<101000> uep;
int N,M;
int in[101010],should[101010];

set<pair<int,int>> DE;
vector<int> V[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>j;
		in[x]^=j;
		in[y]^=j;
		if(j) should[x]=1;
		uf(x,y);
		uep.add_path(x,y);
		if(j==0) uep.add_path(x,y);
	}
	for(i=1;i<=N;i++) V[uf[i]].push_back(i),should[uf[i]]+=should[i];
	
	vector<vector<int>> R;
	for(i=1;i<=N;i++) if(i==uf[i] && should[i]) {
		vector<int> odd;
		FORR(v,V[i]) if(in[v]) odd.push_back(v);
		assert(odd.size()%2==0);
		for(x=2;x<odd.size();x+=2) {
			DE.insert({odd[x],odd[x+1]});
			DE.insert({odd[x+1],odd[x]});
			uep.add_path(odd[x],odd[x+1]);
		}
		uep.path.clear();
		if(odd.size()) uep.dfs(odd[0]);
		else uep.dfs(i);
		int pre=-1;
		R.push_back(vector<int>());
		FORR(p,uep.path) {
			if(DE.count({pre,p})) {
				R.push_back(vector<int>());
			}
			pre=p;
			R.back().push_back(p);
		}
		
	}
	cout<<R.size()<<endl;
	FORR(r,R) {
		cout<<r.size();
		FORR(v,r) cout<<" "<<v;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
