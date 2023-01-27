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

int N,M,K;
int U[303030],V[303030];
int valid[303030];

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
UF<303030> uf;

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
	
	bool GetPath(int root=-1) { // 開始地点を探し、条件を満たすか判定
		int fo=-1,odd=0,i,np=0;
		FOR(i,MV) {
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
				FOR(i,MV) if(E[i].size()) root=i;
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
UndirectedEulerPath<303030> uep;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
	}
	cin>>K;
	FOR(i,K) {
		cin>>x;
		valid[x-1]=1;
	}
	FOR(i,M) if(valid[i]==0) {
		uf(U[i],V[i]);
	}
	FOR(i,M) if(valid[i]==1) {
		uep.add_path(uf[U[i]],uf[V[i]]);
	}
	if(uep.GetPath()) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
