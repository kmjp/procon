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
int P[12];
vector<pair<int,int>> E[12];
int S,T;
ll dp[1<<12][12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>P[i];
	cin>>S>>T;
	S--,T--;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	int mask;
	FOR(mask,1<<N) FOR(i,N) dp[mask][i]=-1LL<<60;
	priority_queue<pair<ll,int>> Q;
	dp[1<<S][S]=P[S];
	
	ll ma=-1LL<<60;
	FOR(j,100) {
		FOR(mask,1<<N) FOR(i,N) if(mask&(1<<i)) {
			FORR2(e,c,E[i]) dp[mask|(1<<e)][e]=max(dp[mask|(1<<e)][e],dp[mask][i]-c+((mask&(1<<e))?0:P[e]));
		}
		FOR(mask,1<<N) ma=max(ma,dp[mask][T]);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
