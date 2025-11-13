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

int T,H,W;
string S[202020];
vector<int> dp[4][202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) {
			cin>>S[y];
			FOR(i,4) {
				dp[i][y].clear();
				dp[i][y].resize(W,1<<30);
			}
		}
		deque<int> Q;
		dp[0][0][0]=0;
		Q.push_back(0);
		int ret=1<<30;
		while(Q.size()) {
			int dir=Q.front()/(H*W);
			int cy=Q.front()%(H*W)/W;
			int cx=Q.front()%W;
			Q.pop_front();
			
			int dy[]={0,0,1,-1};
			int dx[]={1,-1,0,0};
			int dir2;
			FOR(dir2,4) if((dir^1)!=dir2) {
				int ty=cy+dy[dir2];
				int tx=cx+dx[dir2];
				int co=dp[dir][cy][cx]+1;
				if(S[cy][cx]=='A') {
					if(dir==dir2) co--;
				}
				if(S[cy][cx]=='B') {
					if(dir==0&&dir2==2) co--;
					if(dir==1&&dir2==3) co--;
					if(dir==2&&dir2==0) co--;
					if(dir==3&&dir2==1) co--;
				}
				if(S[cy][cx]=='C') {
					if(dir==0&&dir2==3) co--;
					if(dir==1&&dir2==2) co--;
					if(dir==2&&dir2==1) co--;
					if(dir==3&&dir2==0) co--;
				}
				if(ty==H-1&&tx==W) ret=min(ret,co);
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(chmin(dp[dir2][ty][tx],co)) {
					if(co==dp[dir][cy][cx]) Q.push_front(dir2*H*W+ty*W+tx);
					else Q.push_back(dir2*H*W+ty*W+tx);
				}
			}
			
			
			
		}
		
		cout<<ret<<endl;
		
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
