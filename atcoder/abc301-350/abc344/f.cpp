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
ll P[88][88];
ll R[88][88];
ll D[88][88];

pair<ll,ll> dp[88][88][88][88];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>P[y][x];
	FOR(y,N) FOR(x,N-1) cin>>R[y][x];
	FOR(y,N-1) FOR(x,N) cin>>D[y][x];
	
	FOR(y,N) FOR(x,N) FOR(i,N) FOR(j,N) dp[y][x][i][j]={1LL<<60,0};
	dp[0][0][0][0]={0,0};
	
	FOR(y,N) FOR(x,N) {
		FOR(i,N) FOR(j,N) if(P[y][x]>=P[i][j]) chmin(dp[y][x][y][x],dp[y][x][i][j]);
		FOR(i,N) FOR(j,N) if(dp[y][x][i][j].first<1LL<<60) {
			ll cur=-dp[y][x][i][j].second;
			if(y<N-1) {
				ll add=0;
				if(cur<D[y][x]) add=(D[y][x]-cur+P[i][j]-1)/P[i][j];
				chmin(dp[y+1][x][i][j],{dp[y][x][i][j].first+add+1,-(cur-D[y][x]+add*P[i][j])});
			}
			if(x<N-1) {
				ll add=0;
				if(cur<R[y][x]) add=(R[y][x]-cur+P[i][j]-1)/P[i][j];
				chmin(dp[y][x+1][i][j],{dp[y][x][i][j].first+add+1,-(cur-R[y][x]+add*P[i][j])});
			}
		}
	}
	
	ll mi=1LL<<60;
	FOR(y,N) FOR(x,N) mi=min(mi,dp[N-1][N-1][y][x].first);
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
