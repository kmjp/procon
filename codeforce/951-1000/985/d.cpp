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
set<int> E[101010];
vector<vector<int>> R;
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
UF<101010> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		uf.reinit(N);
		R.clear();
		FOR(i,N) E[i].clear();
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].insert(y-1);
			E[y-1].insert(x-1);
		}
		set<pair<int,int>> S;
		FOR(i,N) S.insert({E[i].size(),i});
		while(S.rbegin()->first>=2) {
			x=S.rbegin()->second;
			y=*E[x].begin();
			k=*next(E[x].begin());
			S.erase({E[x].size(),x});
			S.erase({E[y].size(),y});
			S.erase({E[k].size(),k});
			E[x].erase(y);
			E[x].erase(k);
			E[y].erase(x);
			E[k].erase(x);
			if(E[y].count(k)) {
				E[y].erase(k);
				E[k].erase(y);
			}
			else {
				E[y].insert(k);
				E[k].insert(y);
			}
			R.push_back({x+1,y+1,k+1});
			S.insert({E[x].size(),x});
			S.insert({E[y].size(),y});
			S.insert({E[k].size(),k});
		}
		x=y=-1;
		
		FOR(i,N) FORR(e,E[i]) {
			uf(i,e);
			x=i;
			y=e;
		}
		if(x!=-1) {
			FOR(i,N) if(uf[x]!=uf[i]) {
				uf(x,i);
				R.push_back({x+1,y+1,i+1});
				y=i;
			}
		}
		cout<<R.size()<<endl;
		FORR(v,R) {
			FORR(a,v) cout<<a<<" ";
			cout<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
