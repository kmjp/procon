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
int C[4];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};
ll K,P;
int SX,SY,TX,TY;
ll dp[101][101];
string S[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(i,4) cin>>C[i];
	cin>>K>>P;
	cin>>SY>>SX>>TY>>TX;
	SY--,SX--,TY--,TX--;
	
	FOR(y,H) cin>>S[y];
	
	FOR(y,H) FOR(x,W) dp[y][x]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	dp[SY][SX]=(S[SY][SX]=='.')?0:P;
	Q.push({-dp[SY][SX],SY*100+SX});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cy=Q.top().second/100;
		int cx=Q.top().second%100;
		Q.pop();
		if(dp[cy][cx]!=co) continue;
		FOR(i,4) {
			int ty=cy+dy[i];
			int tx=cx+dx[i];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			if(S[ty][tx]=='#') continue;
			ll nco=co+C[i]+(S[ty][tx]=='@'?P:0);
			if(nco<dp[ty][tx]) {
				dp[ty][tx]=nco;
				Q.push({-nco,ty*100+tx});
			}
		}
	}
	
	if(dp[TY][TX]<=K) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
