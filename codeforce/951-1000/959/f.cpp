#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
int N,M;
vector<pair<int,int>> Es;
int NE[505050];
vector<int> E[505050];
int L[505050];
int vis[505050];
int NP[505050];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
	void dump(int num=um) { //グループ分けした配列を作る
		int i;
		FOR(i,num) G[i].clear();
		FOR(i,num) G[operator[](i)].push_back(i);
	}
};
UF<505050> uf;

template<int MV> class UndirectedEulerPath {
public:
	int NV;
	vector<int> path;
	multiset<int> E[MV];
	void add_path(int x,int y) { E[x].insert(y); E[y].insert(x); }

	
	void init(int NV){
		this->NV=NV;
		for(int i=0;i<NV;i++) E[i].clear();
		path.clear();
	}
	void dfs(int cur) {
		while(E[cur].size()) {
			int tar=*E[cur].begin();
			E[cur].erase(E[cur].begin());
			E[tar].erase(E[tar].find(cur));
			dfs(tar);
		}
		path.push_back(cur);
	}
	
	bool GetPath(int root=-1) { // 開始地点を探し、条件を満たすか判定
		int fo=-1,odd=0,i,np=0;
		assert(NV);
		FOR(i,NV) {
			np += E[i].size();
			if(E[i].size()%2) odd++, fo=(fo==-1)?i:fo;
		}
		//閉路なら奇数を許容しないようにしておく
		if(odd!=0 && odd!=2) return false;
		if(root==-1) {
			if(odd) {
				root=fo;
			}
			else {
				FOR(i,NV) if(E[i].size()) root=i;
			}
		}
		else {
			if(odd==2&&E[root].size()%2==0) return false;
		}
		dfs(root);
		reverse(path.begin(),path.end());
		return path.size()==np/2+1;
	}
};

UndirectedEulerPath<501000> uep;

void dfs(int cur) {
	if(vis[cur]) return;
	vis[cur]=1;
	if(L[cur]) {
		NP[cur]=1;
	}
	else {
		NP[cur]=0;
	}
	
	FORR(e,E[cur]) if(vis[e]==0) {
		dfs(e);
		if(NP[e]) {
			Es.push_back({e,cur});
			NP[cur]^=1;
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		uf.reinit(N);
		Es.clear();
		FOR(i,N) {
			E[i].clear();
			NE[i]=0;
			vis[i]=0;
		}
		FOR(i,M) {
			cin>>x>>y>>k;
			x--,y--;
			if(k==0) {
				if(uf[x]!=uf[y]) {
					E[x].push_back(y);
					E[y].push_back(x);
					uf(x,y);
				}
			}
			else {
				Es.push_back({x,y});
				NE[x]++;
				NE[y]++;
			}
		}
		FOR(i,N) {
			L[i]=NE[i]%2;
		}
		FOR(i,N) if(vis[i]==0) {
			dfs(i);
			if(NP[i]) break;
		}
		if(i!=N) {
			cout<<"NO"<<endl;
			continue;
		}
		
		uep.init(N);
		FORR2(a,b,Es) uep.add_path(a,b);
		uep.GetPath(-1);
		
		cout<<"YES"<<endl;
		cout<<uep.path.size()-1<<endl;
		FORR(p,uep.path) cout<<p+1<<" ";
		cout<<endl;
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
