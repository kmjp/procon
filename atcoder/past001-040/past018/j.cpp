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

int H,W,N;
int dp[1<<16][16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	i=0;
	FOR(y,H) {
		cin>>s;
		FOR(x,W) if(s[x]=='#') i|=1<<(y*W+x);
	}
	int mask;
	FOR(mask,1<<16) FOR(j,16) dp[mask][j]=1<<20;
	
	dp[i][0]=0;
	queue<int> Q;
	Q.push(i*16+0);
	while(Q.size()) {
		int cm=Q.front()/16;
		int cy=Q.front()%16/W;
		int cx=Q.front()%16%W;
		Q.pop();
		if(cm==0) {
			cout<<dp[cm][cy*W+cx]<<endl;
			return;
		}
		FOR(i,4) {
			int d[4]={0,1,0,-1};
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W) continue;
			int nm=cm^(1<<(ty*W+tx));
			if(dp[nm][ty*W+tx]==1<<20) {
				dp[nm][ty*W+tx]=dp[cm][cy*W+cx]+1;
				Q.push(nm*16+ty*W+tx);
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
