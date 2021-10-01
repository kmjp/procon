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
pair<ll,ll> P[303];
ll dp[303][303][303][2];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	P[N]={0,0};
	N++;
	sort(P,P+N);
	FOR(i,N) if(P[i].second==0) break;
	ll ma=0;
	FOR(x,N+2) FOR(y,N+2) FOR(k,N+2) dp[x][y][k][0]=dp[x][y][k][1]=-1LL<<60;
	FOR(j,N+1) dp[i][i][j][0]=0;
	
	for(int c=N;c>=0;c--) {
		for(int len=0;len<=N;len++) {
			for(int L=0,R=len;R<N;L++,R++) {
				ma=max(ma,dp[L][R][c][0]);
				ma=max(ma,dp[L][R][c][1]);
				if(L>0) {
					//take
					if(c) chmax(dp[L-1][R][c-1][0],dp[L][R][c][0]+P[L-1].second-c*(P[L].first-P[L-1].first));
					chmax(dp[L-1][R][c][0],dp[L][R][c][0]-c*(P[L].first-P[L-1].first));
					
					if(c) chmax(dp[L-1][R][c-1][0],dp[L][R][c][1]+P[L-1].second-c*(P[R].first-P[L-1].first));
					chmax(dp[L-1][R][c][0],dp[L][R][c][1]-c*(P[R].first-P[L-1].first));
				}
				if(R<N-1) {
					if(c) chmax(dp[L][R+1][c-1][1],dp[L][R][c][0]+P[R+1].second-c*(P[R+1].first-P[L].first));
					chmax(dp[L][R+1][c][1],dp[L][R][c][0]-c*(P[R+1].first-P[L].first));
					
					if(c) chmax(dp[L][R+1][c-1][1],dp[L][R][c][1]+P[R+1].second-c*(P[R+1].first-P[R].first));
					chmax(dp[L][R+1][c][1],dp[L][R][c][1]-c*(P[R+1].first-P[R].first));
				}
			}
		}
	}
	
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
