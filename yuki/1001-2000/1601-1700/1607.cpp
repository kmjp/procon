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
vector<pair<int,int>> E[202020];
int dp[202020];
int can(int v) {
	int i;
	FOR(i,N) dp[i]=1<<20;
	dp[0]=0;
	deque<int> Q;
	Q.push_back(0);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop_front();
		FORR2(e,c,E[cur]) {
			if(c<v) {
				if(dp[e]>dp[cur]) {
					dp[e]=dp[cur];
					Q.push_front(e);
				}
			}
			else {
				if(dp[e]>dp[cur]+1) {
					dp[e]=dp[cur]+1;
					Q.push_back(e);
				}
			}
		}
		
	}
	return dp[N-1];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	int mi=1<<20;
	for(i=19;i>=0;i--) if(can(mi-(1<<i))<K) mi-=1<<i;
	cout<<mi-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
