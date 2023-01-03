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
int A[1010][1010];

int dp[1010][2][2];

int okline(int y,int p0,int p1,int p2) {
	int x;
	FOR(x,W) {
		int c=A[y][x]^p1;
		if(x&&A[y][x]==A[y][x-1]) continue;
		if(x+1<W&&A[y][x]==A[y][x+1]) continue;
		if(y&&c==(A[y-1][x]^p0)) continue;
		if(y+1<H&&c==(A[y+1][x]^p2)) continue;
		return 0;
	}
	return 1;
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	
	int ma=1<<20;
	FOR(y,H) dp[y][0][0]=dp[y][0][1]=dp[y][1][0]=dp[y][1][1]=1<<20;
	
	if(okline(0,0,0,0)) dp[1][0][0]=0;
	if(okline(0,0,1,0)) dp[1][1][0]=1;
	if(okline(0,0,0,1)) dp[1][0][1]=1;
	if(okline(0,0,1,1)) dp[1][1][1]=2;
	
	for(y=2;y<H;y++) {
		FOR(i,2) FOR(j,2) FOR(k,2) {
			if(okline(y-1,i,j,k)) chmin(dp[y][j][k],dp[y-1][i][j]+k);
		}
	}
	
	FOR(i,2) FOR(j,2) if(okline(H-1,i,j,0)) ma=min(ma,dp[H-1][i][j]);
	
	
	
	
	if(ma==1<<20) ma=-1;
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
