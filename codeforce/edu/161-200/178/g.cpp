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


int N;
vector<pair<int,int>> G[202020];
int Q;
int K[202020];
int ret[1<<20];

const int NV=1<<19;
vector<pair<int,int>> ev[1<<20];

template<int um> class UF_pop {
	public:
	vector<int> par,rank; vector<array<int,6>> hist;
	UF_pop() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; hist.clear(); FOR(i,um) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):operator[](par[x]);}
	void pop() {
		if(hist.size()) {
			auto a=hist.back();
			hist.pop_back();
			par[a[0]]=a[1]; rank[a[0]]=a[2];
			par[a[3]]=a[4]; rank[a[3]]=a[5];
		}
	}
	void operator()(int x,int y) {
		x=operator[](x); y=operator[](y);
		hist.push_back({x,par[x],rank[x],y,par[y],rank[y]});
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else rank[x]+=(rank[x]==rank[y]), par[y]=x;
	}
};
UF_pop<404040> uf;

void update(int x,int y, pair<int,int> v,int l=0,int r=NV,int k=1) {
	if(l>=r) return;
	if(x<=l && r<=y) {
		ev[k].push_back(v);
	}
	else if(l < y && x < r) {
		update(x,y,v,l,(l+r)/2,k*2);
		update(x,y,v,(l+r)/2,r,k*2+1);
	}
}


void dfs(int k,int L,int R,int num) {
	int cur=uf.hist.size();
	FORR2(a,b,ev[k]) {
		if(uf[a*2]==uf[b*2+1]) {
			num++;
		}
		uf(a*2,b*2+1);
		uf(a*2+1,b*2);
	}
	
	if(L+1==R) {
		ret[L]=num%2;
	}
	else {
		int M=(L+R)/2;
		dfs(k*2,L,M,num);
		dfs(k*2+1,M,R,num);
	}
	
	
	while(uf.hist.size()>cur) uf.pop();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		G[i].push_back({0,x-1});
	}
	FOR(i,Q) {
		cin>>x>>y>>K[i];
		G[x-1].push_back({i+1,y-1});
	}
	FOR(i,N) {
		G[i].push_back({Q+1,0});
		FOR(j,G[i].size()-1) {
			update(G[i][j].first,G[i][j+1].first,{i,G[i][j].second});
		}
	}
	dfs(1,0,1<<19,0);
	FOR(i,Q) {
		if(K[i]%3!=2) {
			cout<<K[i]%3<<endl;
		}
		else {
			if((N-ret[i+1])%2==0) {
				cout<<1<<endl;
			}
			else {
				cout<<2<<endl;
			}
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
