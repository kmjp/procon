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
int A,B,C,D;
int dp[1010][1010];

queue<int> Q[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) dp[y][x]=1LL<<30;
	}
	cin>>A>>B>>C>>D;
	A--,B--,C--,D--;
	dp[A][B]=0;
	Q[0].push(A*1000+B);
	FOR(i,1<<20) {
		while(Q[i].size()) {
			int cy=Q[i].front()/1000;
			int cx=Q[i].front()%1000;
			Q[i].pop();
			if(dp[cy][cx]!=i) continue;
			
			int dy[]={0,0,1,-1};
			int dx[]={1,-1,0,0};
			FOR(j,4) {
				int ty=cy+dy[j];
				int tx=cx+dx[j];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(S[ty][tx]=='.'&&chmin(dp[ty][tx],i)) Q[i].push(ty*1000+tx);
				if(S[ty][tx]=='#'&&chmin(dp[ty][tx],i+1)) Q[i+1].push(ty*1000+tx);
				ty+=dy[j];
				tx+=dx[j];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(chmin(dp[ty][tx],i+1)) Q[i+1].push(ty*1000+tx);
			}
		}
	}
	cout<<dp[C][D]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
