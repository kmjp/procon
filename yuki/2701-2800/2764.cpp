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
ll W[202020];
vector<pair<int,ll>> E[202020];
ll dp[202020][2];


template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return ((__int128)(A.second-C.second)*(B.first-A.first)<=(__int128)(A.second-B.second)*(C.first-A.first));
	}

	void add(V a, V b) { // add ax+b
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	void add(vector<pair<V,V>> v) {
		sort(ALL(v)); 
		reverse(ALL(v)); //ŒX‚«‚Ì‘å‚«‚¢‡
		FORR2(a,b,v) add(a,b);
		
	}
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(((calc(Q[M],x)>=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};
ConvexHull<ll> ch;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>W[i];
	FOR(i,M) {
		ll v;
		cin>>x>>y>>v;
		x--,y--;
		E[x].push_back({y,v});
		E[y].push_back({x,v});
	}
	FOR(i,N) dp[i][0]=dp[i][1]=1LL<<60;
	dp[0][0]=dp[N-1][1]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	Q.push({0,2*N-1});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second%N;
		int id=Q.top().second/N;
		Q.pop();
		if(dp[cur][id]!=co) continue;
		FORR2(e,c,E[cur]) if(chmin(dp[e][id],co+c)) Q.push({-dp[e][id],id*N+e});
	}
	
	vector<pair<ll,ll>> V;
	FOR(i,N) V.push_back({W[i],dp[i][1]});
	ch.add(V);
	ll ret=dp[N-1][0];
	FOR(i,N) chmin(ret,dp[i][0]+ch.query(W[i]));
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
