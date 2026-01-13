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

int N,M,P;
vector<pair<int,int>> E[4040];
int X[4040],Y[4040],D[2020];
ll dp[4040][4040];
int U[2020],V[2020],W[2020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>P;
	FOR(i,N) {
		cin>>x>>y>>D[i];
		X[i]=x+y;
		Y[i]=x-y;
	}
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		U[i]--,V[i]--;
	}
	
	ll ret=-1;
	FOR(i,2) {
		FOR(j,2) {
			FOR(x,N+1) E[x].clear();
			FOR(x,N) {
				y=(i?X[x]:Y[x]);
				if(j) y=-y;
				E[N].push_back({x,-y+D[x]});
				E[x].push_back({N,y+D[x]});
			}
			FOR(x,M) {
				E[U[x]].push_back({V[x],W[x]});
				E[V[x]].push_back({U[x],W[x]});
			}
			FOR(x,N+M+4) FOR(y,N+2) dp[x][y]=1LL<<60;
			dp[0][N]=0;
			FOR(x,N+M+4) {
				FOR(y,N+2) {
					dp[x+1][y]=min(dp[x+1][y],dp[x][y]);
					FORR2(a,b,E[y]) chmin(dp[x+1][a],dp[x][y]+b);
				}
			}
			int ng=0;
			FOR(x,N+1) if(dp[N+M+2][x]!=dp[N+M+3][x]) {
				cout<<-1<<endl;
				return;
			}
			if(ng==0) ret=max(ret,dp[N+2][P-1]);
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
