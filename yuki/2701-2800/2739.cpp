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

int N,M,X;
vector<pair<int,pair<int,int>>> E[202020];
ll dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X;
	FOR(i,M) {
		cin>>x>>y>>k>>j;
		x--,y--;
		E[x].push_back({y,{j,k}});
		E[y].push_back({x,{j,k}});
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
		ll a=co/1000000;
		ll b=co%1000000;
		FORR2(e,c,E[cur]) {
			ll na=a+c.first;
			ll nb=b+c.second;
			na+=nb/X;
			nb%=X;
			ll v=na*1000000+nb;
			if(chmin(dp[e],v)) Q.push({-dp[e],e});
		}
	}
	
	ll ret=dp[N-1];
	if(ret==1LL<<60) {
		cout<<-1<<endl;
	}
	else {
		ret=ret/1000000+(ret%1000000>0);
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
