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


int N;
ll L;
ll W[22];
ll dp[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,N) cin>>W[i];
	sort(W,W+N);
	
	ll M=W[N-1];
	
	FOR(i,1000000) dp[i]=1LL<<60;
	dp[0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	
	while(Q.size()) {
		ll c=-Q.top().first;
		ll a=Q.top().second;
		Q.pop();
		if(dp[a]!=c) continue;
		FOR(i,N-1) {
			ll v=c+W[i];
			if(dp[v%M]>v) {
				dp[v%M]=v;
				Q.push({-v,v%M});
			}
		}
	}
	
	ll ret=-1;
	FOR(i,M) {
		if(dp[i]<=L) {
			ret+=(L-dp[i])/M+1;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
