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
int A[3030][3030];
int D[3030][3030];
vector<pair<int,int>> E[3030];

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
};
UF<3030> uf;

void dfs(int cur,int pre,int id,int d) {
	D[id][cur]=d;
	if(A[id][cur]!=D[id][cur]) {
		cout<<"No"<<endl;
		exit(0);
	}
	FORR2(e,c,E[cur]) if(e!=pre) dfs(e,cur,id,d+c);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> Es;
	FOR(y,N) {
		for(x=y+1;x<N;x++) {
			cin>>A[y][x];
			A[x][y]=A[y][x];
			Es.push_back({A[y][x],y*10000+x});
		}
	}
	sort(ALL(Es));
	FORR2(d,v,Es) {
		x=v/10000;
		y=v%10000;
		if(uf[x]!=uf[y]) {
			E[x].push_back({y,d});
			E[y].push_back({x,d});
			uf(x,y);
		}
	}
	
	FOR(i,N) {
		dfs(i,i,i,0);
	}
	cout<<"Yes"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
