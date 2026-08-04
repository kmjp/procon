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

int H,W,SY,SX;
string S[202020];
vector<ll> dp[2][10][202020];
int Q,T;
map<int,vector<pair<int,int>>> Ys[2],Xs[2],YpX[2],YmX[2];

int dy[]={-1,-1,-1,0,0,0,1,1,1};
int dx[]={-1,0,1,-1,0,1,-1,0,1};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>SY>>SX;
	SY--,SX--;
	FOR(y,H) {
		cin>>S[y];
		FOR(i,2) FOR(j,10) dp[i][j][y].resize(W,1LL<<60);
	}
	dp[0][9][SY][SX]=0;
	deque<int> Q;
	Q.push_back({9*H*W+SY*W+SX});
	while(Q.size()) {
		int step=Q.front()/(H*W*10);
		int prev=Q.front()/(H*W)%10;
		int cy=Q.front()%(H*W)/W;
		int cx=Q.front()%W;
		Q.pop_front();
		if(prev==4||prev==9) {
			FOR(i,9) if(i!=4) {
				int ty=cy+dy[i];
				int tx=cx+dx[i];
				if(ty>=0&&ty<H&&tx>=0&&tx<W&&S[ty][tx]=='.'&&chmin(dp[step^1][i][ty][tx],dp[step][prev][cy][cx]+1)) Q.push_back((step^1)*H*W*10+i*H*W+ty*W+tx);
			}
		}
		else {
			if(chmin(dp[step][4][cy][cx],dp[step][prev][cy][cx])) Q.push_front(step*H*W*10+4*H*W+cy*W+cx);
			int ty=cy+dy[prev];
			int tx=cx+dx[prev];
			if(ty>=0&&ty<H&&tx>=0&&tx<W&&S[ty][tx]=='.'&&chmin(dp[step][prev][ty][tx],dp[step][prev][cy][cx])) Q.push_front(step*H*W*10+prev*H*W+ty*W+tx);
		}
		
		
	}
	cin>>x;
	while(x--) {
		cin>>SY>>SX>>T;
		if(dp[T%2][4][SY-1][SX-1]<=T) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
