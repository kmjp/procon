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

int N,A,B,C;
ll F[402020];
ll dp[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>C;
	
	F[1]=1;
	for(i=2;i<=2*N;i++) {
		if(i<N) {
			F[i]=F[i-1]*i;
			if(F[i]>=N) F[i]=F[i]%N+N;
		}
		else {
			F[i]=N;
		}
		dp[i]=1LL<<60;
	}
	priority_queue<pair<ll,int>> Q;
	Q.push({0,1});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dp[cur]!=co) continue;
		
		x=cur+1;
		if(x==2*N) x=N;
		if(chmin(dp[x],co+A)) Q.push({-dp[x],x});
		x=F[cur];
		if(chmin(dp[x],co+C)) Q.push({-dp[x],x});
		if(cur!=1) {
			ll v=1,c=1;
			for(i=1;i<=20;i++) {
				v=v*cur;
				c=c*B;
				if(c>1LL*A*N) break;
				if(v>=2*N) v=v%N+N;
				if(chmin(dp[v],co+c)) Q.push({-dp[v],v});
			}
		}
	}
	cout<<dp[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
