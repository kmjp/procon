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
int dp[3030][3030];
priority_queue<pair<int,int>> Q;

void go(int cy,int cx) {
	if(cy<0||cy>=H||cx<0||cx>=W) return;
	
	int mi=0;
	int i,j;
	int dy[]={1,0,-1,0};
	int dx[]={0,1,0,-1};
	FOR(i,4) {
		int tmp=1<<30;
		FOR(j,4) if(i!=j) {
			int ty=cy+dy[j];
			int tx=cx+dx[j];
			if(ty>=0&&ty<H&&tx>=0&&tx<W) tmp=min(tmp,dp[ty][tx]+1);
		}
		mi=max(mi,tmp);
	}
	if(mi<dp[cy][cx]) {
		dp[cy][cx]=mi;
		Q.push({-mi,cy*3000+cx});
	}
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) FOR(x,W) dp[y][x]=1<<30;
	FOR(i,K) {
		cin>>y>>x;
		y--,x--;
		dp[y][x]=0;
		Q.push({0,y*3000+x});
	}
	while(Q.size()) {
		int co=-Q.top().first;
		int cy=Q.top().second/3000;
		int cx=Q.top().second%3000;
		Q.pop();
		if(dp[cy][cx]!=co) continue;
		go(cy-1,cx);
		go(cy+1,cx);
		go(cy,cx-1);
		go(cy,cx+1);
	}
	ll ret=0;
	FOR(y,H) FOR(x,W) if(dp[y][x]<=1<<29) ret+=dp[y][x];
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
