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

int N,M;
int dp[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,1010) FOR(x,1010) dp[y][x]=1<<20;
	queue<int> Q;
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		dp[y][x]=0;
		Q.push(y*1010+x);
	}
	while(Q.size()) {
		int cy=Q.front()/1010;
		int cx=Q.front()%1010;
		Q.pop();
		int d[]={0,1,0,-1};
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(tx<0||tx>=1001||ty<0||ty>=1000) continue;
			if(dp[ty][tx]==1<<20) {
				dp[ty][tx]=dp[cy][cx]+1;
				Q.push(ty*1010+tx);
			}
		}
	}
	int mi=101010;
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		mi=min(mi,dp[y][x]);
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
