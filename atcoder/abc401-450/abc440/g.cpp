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

int F,H,W;
string S[10][505];
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
UF<505*505*10> uf;

int dp[10*500*500];
vector<pair<int,int>> dp2[10*500*500];
vector<pair<int,int>> dp3[10*500*500];
vector<pair<int,int>> dp4[10*500*500];
set<int> up[10*500*500],down[10*500*500];

int Q,G,A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>F>>H>>W;
	FOR(k,F) {
		FOR(y,H) {
			cin>>S[k][y];
			FOR(x,W) if(S[k][y][x]!='#') {
				if(y&&S[k][y-1][x]!='#') uf(k*500*500+y*500+x,k*500*500+(y-1)*500+x);
				if(x&&S[k][y][x-1]!='#') uf(k*500*500+y*500+x,k*500*500+y*500+x-1);
			}
		}
	}
	FOR(k,F) {
		FOR(y,H) FOR(x,W) if(S[k][y][x]!='#') {
			dp[uf[k*500*500+y*500+x]]+=S[k][y][x]-'0';
			if(k&&S[k-1][y][x]!='#') {
				up[uf[(k-1)*500*500+y*500+x]].insert(uf[k*500*500+y*500+x]);
				down[uf[k*500*500+y*500+x]].insert(uf[(k-1)*500*500+y*500+x]);
			}
		}
	}
	//梯子無しの場合の最大値
	for(k=F-1;k>=0;k--) FOR(y,H) FOR(x,W) if(S[k][y][x]!='#'&&uf[k*500*500+y*500+x]==k*500*500+y*500+x) {
		int v=k*500*500+y*500+x;
		dp2[v].push_back({dp[v],-1});
		FORR(u,up[v]) dp2[v].push_back({dp[v]+dp2[u][0].first,u});
		sort(ALL(dp2[v]));
		reverse(ALL(dp2[v]));
		if(dp2[v].size()>2) dp2[v].resize(2);
		/*
		cout<<v<<" "<<dp[v]<<" ";
		FORR2(a,b,dp2[v]) cout<<a<<":"<<b<<" ";
		cout<<endl;
		*/
	}
	//今すぐ梯子を使う場合の最大値
	FOR(k,F) FOR(y,H) FOR(x,W) if(S[k][y][x]!='#'&&uf[k*500*500+y*500+x]==k*500*500+y*500+x) {
		int v=k*500*500+y*500+x;
		dp3[v].push_back(dp2[v][0]);
		if(dp2[v].size()==2) dp3[v].push_back(dp2[v][1]);
		FORR(d,down[v]) {
			if(dp2[d][0].second!=v) dp3[v].push_back({dp[v]+dp2[d][0].first,d});
			else {
				//戻ってくる
				//戻らない
				dp3[v].push_back({max(dp2[v][0].first+dp[d],dp[v]+dp2[d][1].first),d});
			}
		}
		sort(ALL(dp3[v]));
		reverse(ALL(dp3[v]));
		if(dp3[v].size()>2) dp3[v].resize(2);
		/*
		cout<<v<<" ";
		FORR2(a,b,dp3[v]) cout<<a<<":"<<b<<" ";
		cout<<endl;
		*/
	}
	//途中で1回梯子を使う場合の最大値
	for(k=F-1;k>=0;k--) FOR(y,H) FOR(x,W) if(S[k][y][x]!='#'&&uf[k*500*500+y*500+x]==k*500*500+y*500+x) {
		int v=k*500*500+y*500+x;
		dp4[v].push_back(dp3[v][0]);
		if(dp3[v].size()==2) dp4[v].push_back(dp3[v][1]);
		FORR(u,up[v]) {
			if(dp4[u][0].second!=v) dp4[v].push_back({dp[v]+dp4[u][0].first,u});
			else {
				//2つ目の候補に行く
				int c1=dp[v]+dp4[u][1].first;
				//戻ってくる
				int c2=dp2[v][dp2[v][0].second==u].first+dp[u];
				dp4[v].push_back({max(c1,c2),u});
			}
		}
		sort(ALL(dp4[v]));
		reverse(ALL(dp4[v]));
		if(dp4[v].size()>2) dp4[v].resize(2);
		/*
		cout<<v<<" ";
		FORR2(a,b,dp4[v]) cout<<a<<":"<<b<<" ";
		cout<<endl;
		*/
	}
	cin>>Q;
	while(Q--) {
		cin>>G>>A>>B;
		G--,A--,B--;
		cout<<dp4[uf[G*500*500+A*500+B]][0].first<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
