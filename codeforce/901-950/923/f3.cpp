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

int T,N,M;
set<int> E[202020];
vector<int> R;
int from[202020];
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
UF<202020> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		uf.reinit(N);
		FOR(i,N) {
			E[i].clear();
			from[i]=-1;
		}
		vector<vector<int>> Es;
		FOR(i,M) {
			cin>>x>>y>>k;
			Es.push_back({k,x-1,y-1});
		}
		sort(ALL(Es));
		reverse(ALL(Es));
		x=y=-1;
		int B,K;
		FORR(e,Es) {
			if(uf[e[1]]==uf[e[2]]) {
				x=e[1];
				y=e[2];
				B=e[0];
			}
			else {
				uf(e[1],e[2]);
			}
		}
		FORR(e,Es) {
			if(x==e[1]&&y==e[2]) continue;
			E[e[1]].insert(e[2]);
			E[e[2]].insert(e[1]);
		}
		
		from[x]=x;
		queue<int> Q;
		Q.push(x);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(e,E[cur]) if(from[e]==-1) {
				from[e]=cur;
				Q.push(e);
			}
		}
		vector<int> ret={y};
		while(ret.back()!=x) ret.push_back(from[ret.back()]);
		cout<<B<<" "<<ret.size()<<endl;
		FORR(a,ret) cout<<a+1<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
