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
ll A,B,C;
ll D[1010][1010];
ll dp[1010][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>C;
	FOR(y,N) FOR(x,N) cin>>D[y][x];
	FOR(x,N) dp[x][0]=dp[x][1]=1LL<<60;
	dp[0][0]=dp[0][1]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	Q.push({0,1});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second/2;
		int id=Q.top().second%2;
		Q.pop();
		if(dp[cur][id]!=co) continue;
		if(id==0&&dp[cur][1]>dp[cur][0]) {
			dp[cur][1]=dp[cur][0];
			Q.push({-co,cur*2+1});
		}
		FOR(i,N) {
			ll co2=co+(id==0?(D[cur][i]*A):(D[cur][i]*B+C));
			if(chmin(dp[i][id],co2)) Q.push({-co2,i*2+id});
		}
		
		
	}
	cout<<min(dp[N-1][0],dp[N-1][1])<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
