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

int N,K;
int A[202020];
ll dp1[202020][6];
ll dp2[202020][6];
vector<int> E[202020];

void dfs(int cur,int pre) {
	int i,x,y;
	ll from[3][6];
	FOR(x,3) FOR(y,K+1) from[x][y]=-1LL<<60;
	from[0][0]=0;
	from[1][1]=from[2][1]=A[cur];
	
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		ll to[3][6];
		FOR(x,3) FOR(y,K+1) to[x][y]=from[x][y];
		
		FOR(x,K+1) FOR(y,K+1) {
			//1–{–Ú
			if(x+y<=K) {
				chmax(to[1][x+y],from[0][x]+dp1[e][y]+A[cur]);
				chmax(to[2][x+y],from[0][x]+dp1[e][y]+A[cur]);
			}
			//2–{–Ú
			if(x&&y&&x+y-1<=K) chmax(to[2][x+y-1],from[1][x]+dp1[e][y]);
			if(x+y<=K) {
				chmax(to[0][x+y],from[0][x]+dp2[e][y]);
				chmax(to[1][x+y],from[1][x]+dp2[e][y]);
				chmax(to[2][x+y],from[2][x]+dp2[e][y]);
			}
		}
		FOR(x,3) FOR(y,K+1) from[x][y]=to[x][y];
		
	}
	FOR(y,K+1) {
		dp1[cur][y]=from[1][y];
		dp2[cur][y]=max(from[0][y],from[2][y]);
	}
		
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	ll ret=0;
	FOR(i,K+1) ret=max(ret,dp2[0][i]);
	cout<<ret<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
