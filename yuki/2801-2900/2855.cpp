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


int H,W,K;
int A[303][303];
int dp[303][303];

int hoge(int v) {
	if(v>1000000000) return K+1;
	int y,x;
	FOR(y,H) FOR(x,W) dp[y][x]=1<<30;
	dp[0][0]=A[0][0]<v;
	priority_queue<pair<int,int>> Q;
	Q.push({-dp[0][0],0});
	while(Q.size()) {
		int co=-Q.top().first;
		int cy=Q.top().second/W;
		int cx=Q.top().second%W;
		Q.pop();
		int d[]={0,1,0,-1};
		int i;
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			if(chmin(dp[ty][tx],co+(A[ty][tx]<v))) Q.push({-dp[ty][tx],ty*W+tx});
		}
	}
	return dp[H-1][W-1];
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	
	int ret=1;
	for(i=30;i>=0;i--) if(hoge(ret+(1<<i))<=K) ret+=1<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
