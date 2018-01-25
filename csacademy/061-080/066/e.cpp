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



int N;
int X[201010],Y[201010];
int O[201010];
map<pair<int,int>,set<int>> M;
int L[201010];
vector<int> cand[101010];

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
	
	vector<int> GetPath(vector<int> V) {
		vector<int> O;
		
		FORR(v,V) if(E[v].size()%2) O.push_back(v);
		for(int i=1;i+1<(int)O.size()-1;i+=2) {
			add_path(O[i],O[i+1]);
		}
		
		path.clear();
		if(O.empty()) dfs(V[0]);
		else dfs(O[0]);
		return path;
	}
};
UndirectedEulerPath<201000> uep;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i+1]>>Y[i+1];
		uep.add_path(X[i+1],Y[i+1]);
		uf(X[i+1],Y[i+1]);
		M[{X[i+1],Y[i+1]}].insert(i+1);
		M[{Y[i+1],X[i+1]}].insert(-(i+1));
	}
	
	vector<int> V;
	for(i=1;i<=100000;i++) cand[uf[i]].push_back(i);
	for(k=1;k<=100000;k++) if(cand[k].size()) {
		if(cand[k].size()==1 && uep.E[k].empty()) continue;
		vector<int> p=uep.GetPath(cand[k]);
		//FORR(pp,p) cout<<pp<<"/";
		//cout<<endl;
		FOR(i,p.size()-1) {
			x=p[i];
			y=p[i+1];
			
			if(M.count({x,y})==0) continue;
			if(M[{x,y}].empty()) continue;
			
			j=*M[{x,y}].begin();
			//cout<<j<<endl;
			if(j<0) {
				j=-j;
				swap(x,y);
				O[j]=1;
			}
			V.push_back(j);
			L[j]=V.size();
			M[{x,y}].erase(j);
			M[{y,x}].erase(-j);
		}
	}
	
	set<int> S;
	FOR(i,N+2) S.insert(i);
	//for(i=1;i<=N;i++) _P("!%d %d\n",i,L[i]);
	FOR(i,N-1) {
		cin>>x;
		x=L[x];
		auto nex=S.lower_bound(x+1);
		auto cur=nex;
		cur--;
		if(*nex==N+1) {
			nex--;
			cur--;
		}
		//_P("%d %d %d %d\n",V[*cur-1],V[*nex-1], *cur-1,*nex-1);
		_P("%d %d\n",V[*cur-1],V[*nex-1]);
		S.erase(nex);
	}
	FOR(i,N) _P("%d%c",O[i+1],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
