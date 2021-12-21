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
int A[202020],B[202020];
vector<pair<int,int>> Bs;
set<int> S;
ll dp[404040];

vector<pair<int,int>> E[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>B[i];
		Bs.push_back({B[i],i});
		Bs.push_back({B[i]+M,i});
	}
	sort(ALL(Bs));

	
	FOR(i,N) {
		x=Bs[i].second;
		y=Bs[i+1].second;
		E[N+x].push_back({N+y,Bs[i+1].first-Bs[i].first});
		E[N+i].push_back({i,0});
	}
	
	FOR(i,N) {
		int mi=M-A[i];
		int cur=lower_bound(ALL(Bs),make_pair(mi,-1))-Bs.begin();
		
		E[i].push_back({N+Bs[cur].second,(Bs[cur].first+A[i])%M});
	}
	
	FOR(i,2*N) dp[i]=1LL<<60;
	dp[0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dp[cur]!=co) continue;
		FORR2(e,c,E[cur]) if(dp[e]>co+c) {
			dp[e]=co+c;
			Q.push({-dp[e],e});
		}
	}
	cout<<dp[N-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
