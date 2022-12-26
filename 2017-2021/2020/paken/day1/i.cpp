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
int SY,SX,GY,GX;
string S[2020];
int dp[2020][2020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>SY>>SX>>GY>>GX;
	SY--,SX--,GY--,GX--;
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) dp[y][x][0]=dp[y][x][1]=1<<25;
	dp[SY][SX][0]=dp[SY][SX][1]=0;
	queue<int> Q;
	Q.push(SY*2000+SX);
	Q.push(SY*2000+SX+4000000);
	
	while(Q.size()) {
		int id=Q.front()/4000000;
		int cy=Q.front()%4000000/2000;
		int cx=Q.front()%2000;
		Q.pop();
		
		if(cy==GY&&cx==GX) {
			cout<<dp[cy][cx][id]<<endl;
			return;
		}
		
		FOR(i,4) {
			int dy[4]={1,-1,0,0};
			int dx[4]={0,0,1,-1};
			if(id==0&&i>1) continue;
			if(id==1&&i<=1) continue;
			int ty=cy+dy[i];
			int tx=cx+dx[i];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			if(S[ty][tx]=='#') continue;
			if(dp[ty][tx][id^1]>dp[cy][cx][id]+1) {
				dp[ty][tx][id^1]=dp[cy][cx][id]+1;
				Q.push(ty*2000+tx+(id^1)*4000000);
			}
			
		}
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
