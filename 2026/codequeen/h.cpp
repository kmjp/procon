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
int id[404040];
vector<pair<int,int>> E[404040];
vector<array<int,3>> ev;
ll dp[404040];

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
UF<404040> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	int ON=N;
	FOR(i,M) {
		cin>>x>>y>>j>>k;
		x--,y--;
		E[x].push_back({y,k});
		E[y].push_back({x,k});
		ev.push_back({j,x,y});
	}
	FOR(i,K) {
		cin>>x>>y;
		ev.push_back({y,-1,x-1});
	}
	sort(ALL(ev));
	reverse(ALL(ev));
	
	FOR(i,N) id[i]=i;
	FORR(e,ev) {
		if(e[1]==-1) {
			//“®•¨
			x=uf[e[2]];
			E[e[2]].push_back({id[uf[x]],0});
		}
		else {
			x=uf[e[1]];
			y=uf[e[2]];
			if(x!=y) {
				E[N].push_back({id[x],0});
				E[N].push_back({id[y],0});
				id[uf(x,y)]=N;
				N++;
			}
		}
	}
	FOR(i,N) dp[i]=1LL<<60;
	dp[0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dp[cur]!=co) continue;
		FORR2(e,c,E[cur]) if(chmin(dp[e],co+c)) Q.push({-dp[e],e});
	}
	cout<<dp[ON-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
