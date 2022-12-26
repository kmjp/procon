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
string S[1010];
int SY,SX,TY,TX;
int dp[1010][1010][4];

int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>SY>>SX>>TY>>TX;
	FOR(y,H) cin>>S[y];
	SY--,SX--,TY--,TX--;
	FOR(y,H) FOR(x,W) FOR(i,4) dp[y][x][i]=1<<30;
	deque<int> Q;
	FOR(i,4) {
		dp[SY][SX][i]=0;
		Q.push_back({SY*10000+SX*10+i});
	}
	
	while(Q.size()) {
		int cy=Q.front()/10000;
		int cx=Q.front()/10%1000;
		int d=Q.front()%10;
		Q.pop_front();
		if(cy==TY&&cx==TX) {
			cout<<dp[TY][TX][d]<<endl;
			return;
		}
		
		//change dir
		FOR(i,4) {
			if(dp[cy][cx][i]>dp[cy][cx][d]+1) {
				dp[cy][cx][i]=dp[cy][cx][d]+1;
				Q.push_back({cy*10000+cx*10+i});
			}
		}
		int ty=cy+dy[d];
		int tx=cx+dx[d];
		if(ty>=0&&ty<H&&tx>=0&&tx<W&&S[ty][tx]!='#'&&dp[ty][tx][d]>dp[cy][cx][d]) {
			dp[ty][tx][d]=dp[cy][cx][d];
			Q.push_front({ty*10000+tx*10+d});
		}
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
