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

int T,N,X,A[101];
int dp[102][102][102];
int dp2[102][102][102];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X;
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
		}
		FOR(x,N+1) FOR(y,N+1) FOR(k,X) dp[x][y][k]=dp2[x][y][k]=101010;
		FOR(i,N) {
			FOR(j,X) {
				if(A[i]==j) {
					dp[i][i+1][j]=0;
					dp2[i][i+1][j]=1;
				}
				else {
					dp[i][i+1][j]=1;
					dp2[i][i+1][j]=0;
				}
			}
		}
		for(int len=2;len<=N;len++) {
			for(x=0;x+len<=N;x++) FOR(y,X) {
				for(k=x+1;k<x+len;k++) {
					chmin(dp[x][x+len][y],dp[x][k][y]+dp[k][x+len][y]);
					chmin(dp2[x][x+len][y],dp2[x][k][y]+dp2[k][x+len][y]);
				}
			}
			for(x=0;x+len<=N;x++) {
				priority_queue<pair<int,int>> Q;
				FOR(y,X) {
					Q.push({-dp[x][x+len][y],y*2});
					Q.push({-dp2[x][x+len][y],y*2+1});
				}
				while(Q.size()) {
					int co=-Q.top().first;
					int id=Q.top().second%2;
					y=Q.top().second/2;
					Q.pop();
					if(id==0) {
						FOR(k,X) if(k!=y&&chmin(dp2[x][x+len][k],co)) Q.push({-dp2[x][x+len][k],2*k+1});
					}
					else {
						if(chmin(dp[x][x+len][y],co+1)) Q.push({-dp[x][x+len][y],2*y});
					}
				}
			}
		}
		int mi=1<<20;
		FOR(x,X) mi=min(mi,dp[0][N][x]);
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
