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

int dp[1602020];
vector<int> E[1602020];

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
UF<1402020> uf[3];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		FOR(i,3*N) E[i].clear();
		cin>>N>>M;
		FOR(i,3) uf[i].reinit(3*N);
		FOR(i,M) {
			cin>>x>>y>>k;
			if(k==1) {
				E[x-1].push_back(y-1);
				E[y-1].push_back(x-1);
			}
			uf[k-1](x-1,y-1);
		}
		map<pair<int,int>,int> mp;
		FOR(i,N) {
			mp[{uf[1][i],uf[2][i]}]=0;
		}
		int cur=N;
		FORR2(a,b,mp) mp[a]=cur++;
		FOR(i,cur)  dp[i]=0;
		FOR(i,N) {
			x=mp[{uf[1][i],uf[2][i]}];
			E[x].push_back(i);
			E[i].push_back(x);
		}
		
		queue<int> Q;
		dp[0]=1;
		Q.push(0);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(e,E[cur]) if(chmax(dp[e],1)) Q.push(e);
		}
		vector<int> V;
		FOR(i,N) if(dp[i]) V.push_back(i+1);
		cout<<V.size()<<endl;
		FORR(v,V) cout<<v<<" ";
		cout<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
