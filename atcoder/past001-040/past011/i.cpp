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
string S[55];

int dp[55][55][55][55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int SX,SY,GX,GY,AX,AY;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='s') S[y][x]='.', SX=x,SY=y;
			if(S[y][x]=='g') S[y][x]='.', GX=x,GY=y;
			if(S[y][x]=='a') S[y][x]='.', AX=x,AY=y;
		}
	}
	int y1,y2,x1,x2;
	FOR(y1,55) FOR(y2,55) FOR(x1,55) FOR(x2,55) dp[y1][x1][y2][x2]=1<<30;
	dp[SY][SX][AY][AX]=0;
	queue<int> Q;
	Q.push(SY*50*50*50+SX*50*50+AY*50+AX);
	while(Q.size()) {
		int cy=Q.front()/(50*50*50);
		int cx=Q.front()/(50*50)%50;
		int ay=Q.front()/50%50;
		int ax=Q.front()%50;
		Q.pop();
		
		if(ay==GY&&ax==GX) {
			cout<<dp[cy][cx][ay][ax]<<endl;
			return;
		}
		int d[4]={0,1,0,-1};
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			int t2y=ay;
			int t2x=ax;
			if(ty==ay&&tx==ax) {
				t2y=ay+d[i];
				t2x=ax+d[i^1];
			}
			if(ty<0||t2y<0) continue;
			if(ty>=H||t2y>=H) continue;
			if(tx<0||t2x<0) continue;
			if(tx>=W||t2x>=W) continue;
			if(S[ty][tx]=='#') continue;
			if(S[t2y][t2x]=='#') continue;
			if(dp[ty][tx][t2y][t2x]==1<<30) {
				dp[ty][tx][t2y][t2x]=dp[cy][cx][ay][ax]+1;
				Q.push(ty*50*50*50+tx*50*50+t2y*50+t2x);
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
