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
unordered_set<int> S[203030];
unordered_map<int,int> M[202021];
vector<pair<int,int>> V;
vector<int> R[202021];
vector<int> C[202021];

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
UF<4<<20> uf;

void add(int x,int y) {
	V.push_back({x,y});
	R[y].push_back(x);
	R[y].push_back(0);
	R[y].push_back(202020);
	C[x].push_back(0);
	C[x].push_back(y);
	C[x].push_back(202020);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	add(0,0);
	add(202020,202020);
	FOR(i,N) {
		cin>>x>>y;
		x+=10,y+=10;
		S[x].insert(y);
		add(x,y);
		add(x+1,y);
		add(x,y+1);
		add(x-1,y);
		add(x,y-1);
		add(x+1,y+1);
		add(x+1,y-1);
		add(x-1,y+1);
		add(x-1,y-1);
	}
	
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,V.size()) M[V[i].first][V[i].second]=i;
	FOR(y,202021) if(R[y].size()) {
		sort(ALL(R[y]));
		R[y].erase(unique(ALL(R[y])),R[y].end());
		FOR(x,R[y].size()-1) {
			int px=R[y][x];
			int qx=R[y][x+1];
			if(S[px].count(y)) continue;
			if(S[qx].count(y)) continue;
			uf(M[px][y],M[qx][y]);
		}
	}
	FOR(x,202021) if(C[x].size()) {
		sort(ALL(C[x]));
		C[x].erase(unique(ALL(C[x])),C[x].end());
		FOR(y,C[x].size()-1) {
			int py=C[x][y];
			int qy=C[x][y+1];
			if(S[x].count(py)) continue;
			if(S[x].count(qy)) continue;
			uf(M[x][py],M[x][qy]);
		}
	}
	ll ret=0;
	FOR(y,202020) if(R[y].size()) {
		FOR(x,R[y].size()-1) {
			int px=R[y][x];
			int qx=R[y][x+1];
			if(S[px].count(y)) continue;
			if(uf[M[px][y]]!=uf[M[0][0]]) ret+=qx-px;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
