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
int P[5050];
vector<pair<int,ll>> E[2525];
ll H[2525];
ll dp[2525][2525];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>P[i];
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
	}
	
	priority_queue<pair<ll,int>> Q;
	FOR(i,N) Q.push({0,i});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(H[cur]!=co) continue;
		FORR2(e,c,E[cur]) if(chmin(H[e],co+c)) Q.push({-H[e],e});
	}
	
	FOR(i,N) {
		FORR2(e,c,E[i]) c=c+H[i]-H[e];
	}
	ll mi=1LL<<60;
	int num=0;
	FOR(i,N) {
		FOR(j,N) dp[i][j]=1LL<<60;
		dp[i][i]=0;
		Q.push({0,i});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[i][cur]!=co) continue;
			FORR2(e,c,E[cur]) if(chmin(dp[i][e],co+c)) Q.push({-dp[i][e],e});
		}
		FOR(j,N) if(i!=j) {
			ll c=dp[i][j]-H[i]+H[j]+P[i]+P[j];
			if(c<mi) mi=c, num=0;
			if(c==mi) num++;
		}
	}
	cout<<mi<<" "<<num<<endl;
			
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
