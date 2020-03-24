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
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<202020> uf;

int H,W,P,Q;
string S[2020];
int D[2020][2020],F[2020][2020];
vector<pair<int,int>> E[202020];

int par[30][200005];
int ma[30][200005];
int dep[200005];

void dfs(int cur) {
	FORR(e,E[cur]) if(e.first!=par[0][cur]) {
		dep[e.first]=dep[cur]+1;
		par[0][e.first]=cur;
		ma[0][e.first]=e.second;
		dfs(e.first);
	}
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>P>>Q;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) D[y][x]=1<<30;
	}
	queue<int> PQ;
	FOR(i,P) {
		cin>>y>>x;
		y--,x--;
		D[y][x]=0;
		F[y][x]=i;
		PQ.push(y*10000+x);
	}
	while(PQ.size()) {
		int cy=PQ.front()/10000;
		int cx=PQ.front()%10000;
		int dd[4]={0,1,0,-1};
		PQ.pop();
		FOR(i,4) {
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
			if(D[ty][tx]>D[cy][cx]+1) {
				D[ty][tx]=D[cy][cx]+1;
				F[ty][tx]=F[cy][cx];
				PQ.push(ty*10000+tx);
			}
		}
	}
	
	vector<vector<int>> cand;
	FOR(y,H) FOR(x,W) if(D[y][x]<1<<30) {
		if(y&&D[y-1][x]<1<<30 && F[y][x]!=F[y-1][x]) cand.push_back({D[y][x]+D[y-1][x],F[y-1][x],F[y][x]});
		if(x&&D[y][x-1]<1<<30 && F[y][x]!=F[y][x-1]) cand.push_back({D[y][x]+D[y][x-1],F[y][x-1],F[y][x]});
	}
	sort(ALL(cand));
	FORR(e,cand) {
		if(uf[e[1]]!=uf[e[2]]) {
			uf(e[1],e[2]);
			E[e[1]].push_back({e[2],e[0]});
			E[e[2]].push_back({e[1],e[0]});
		}
	}
	FOR(i,P) if(uf[i]==i) {
		dfs(i);
	}
	FOR(i,19) FOR(x,P) {
		par[i+1][x]=par[i][par[i][x]];
		ma[i+1][x]=max(ma[i][x],ma[i][par[i][x]]);
	}
	while(Q--) {
		cin>>x>>y;
		x--,y--;
		if(uf[x]!=uf[y]) {
			cout<<-1<<endl;
			continue;
		}
		if(dep[x]<dep[y]) swap(x,y);
		int ret=0;
		for(i=20;i>=0;i--) if(dep[y]+(1<<i)<=dep[x]) {
			ret=max(ret,ma[i][x]);
			x=par[i][x];
		}
		for(i=20;i>=0;i--) if(par[i][x]!=par[i][y]) {
			ret=max(ret,ma[i][y]);
			ret=max(ret,ma[i][x]);
			x=par[i][x];
			y=par[i][y];
		}
		//cout<<x<<dep[x]<<" "<<y<<dep[y]<<" "<<ret<<endl;
		if(x!=y) {
			ret=max(ret,ma[0][y]);
			ret=max(ret,ma[0][x]);
		}
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
