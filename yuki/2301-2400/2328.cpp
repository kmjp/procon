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

int H,W;
ll A[888][888];
ll dp[888][888];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	H-=2;
	FOR(y,H) FOR(x,W) cin>>A[y][x+1];
	W+=2;
	FOR(y,H) FOR(x,W) dp[y][x]=1LL<<60;
	dp[0][0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cy=Q.top().second/1000;
		int cx=Q.top().second%1000;
		Q.pop();
		if(dp[cy][cx]!=co) continue;
		for(int ty=cy-1;ty<=cy+1;ty++) 
			for(int tx=cx-1;tx<=cx+1;tx++) {
				if(ty<0||ty>=H||tx<0||tx>=W||A[ty][tx]==-1) continue;
				if(chmin(dp[ty][tx],co+A[ty][tx])) {
					Q.push({-dp[ty][tx],ty*1000+tx});
				}
			}
	}
	ll ret=dp[H-1][W-1];
	if(ret==1LL<<60) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
