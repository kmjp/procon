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


int N,M;
int P[1010],R[1010],A[202020],B[202020];
set<int> E[1010];
map<pair<int,int>,int> Es;

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
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
};
UF<1010> uf;

vector<int> S,ret;

void go(int i) {
	swap(P[A[i]],P[B[i]]);
	R[P[A[i]]]=A[i];
	R[P[B[i]]]=B[i];
	ret.push_back(i+1);
}

void dfs(int cur,int pre,int tar,vector<int>& V) {
	if(P[cur]==tar) {
		S=V;
		return;
	}
	FORR(e,E[cur]) if(e!=pre) {
		V.push_back(Es[{cur,e}]);
		dfs(e,cur,tar,V);
		V.pop_back();
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i+1];
		R[P[i+1]]=i+1;
	}
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		if(uf[x]!=uf[y]) {
			uf(x,y);
			E[x].insert(y);
			E[y].insert(x);
		}
		A[i]=x;
		B[i]=y;
		Es[{x,y}]=Es[{y,x}]=i;
	}
	
	queue<int> Q;
	FOR(i,N) if(E[i+1].size()<=1) Q.push(i+1);
	
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		
		if(uf[R[x]]!=uf[x]) {
			cout<<"-1"<<endl;
			return;
		}
		S.clear();
		vector<int> W;
		dfs(x,x,x,W);
		while(S.size()) {
			go(S.back());
			S.pop_back();
		}
		
		FORR(e,E[x]) {
			E[e].erase(x);
			if(E[e].size()<=1) Q.push(e);
		}
	}
	
	cout<<ret.size()<<endl;
	FORR(r,ret) cout<<r<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
