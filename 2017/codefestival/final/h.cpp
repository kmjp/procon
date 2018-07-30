#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W,py,px;
string S[41];
int sum[41][41];
int dp[41][41][41][41];
int memo[41][41][41][41];
int num(int L,int T,int R,int D) {
	if(R<=L || D<=T) return 0;
	if(memo[L][T][R][D]==-1) {
		memo[L][T][R][D]=sum[D][R]-sum[D][L]-sum[T][R]+sum[T][L];
	}
	return memo[L][T][R][D];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='P') py=y,px=x;
			sum[y+1][x+1]=sum[y][x+1]+sum[y+1][x]-sum[y][x]+(S[y][x]=='#');
		}
	}
	FOR(i,41) FOR(j,41) FOR(x,41) FOR(y,41) dp[i][j][x][y]=101010;
	dp[0][0][H][W]=0;
	
	int ret=101010;
	int y2,x2;
	for(int h=H;h>=1;h--) for(int w=W;w>=1;w--) {
		FOR(y,H-h+1) FOR(x,W-w+1) {
			// LU
			for(x2=0;x2<=x;x2++) for(y2=0;y2<=y;y2++)     dp[y][x][y+h][x+w]=min(dp[y][x][y+h][x+w],dp[y2][x2][y+h][x+w]+num(x,y2,x+w,y)  +num(x2,y,x,y+h));
			// RU
			for(x2=x+w;x2<=W;x2++) for(y2=0;y2<=y;y2++)   dp[y][x][y+h][x+w]=min(dp[y][x][y+h][x+w],dp[y2][x][y+h][x2]  +num(x,y2,x+w,y)  +num(x+w,y,x2,y+h));
			// LD
			for(x2=0;x2<=x;x2++) for(y2=y+h;y2<=H;y2++)   dp[y][x][y+h][x+w]=min(dp[y][x][y+h][x+w],dp[y][x2][y2][x+w]  +num(x,y+h,x+w,y2)+num(x2,y,x,y+h));
			// RU
			for(x2=x+w;x2<=W;x2++) for(y2=y+h;y2<=H;y2++) dp[y][x][y+h][x+w]=min(dp[y][x][y+h][x+w],dp[y][x][y2][x2]    +num(x,y+h,x+w,y2)+num(x+w,y,x2,y+h));
			
			if(y<=py && py<y+h && x<=px && px<x+w) {
				ret=min(ret,dp[y][x][y+h][x+w]+num(x,y,px+1,py+1));
				ret=min(ret,dp[y][x][y+h][x+w]+num(px,y,x+w,py+1));
				ret=min(ret,dp[y][x][y+h][x+w]+num(x,py,px+1,y+h));
				ret=min(ret,dp[y][x][y+h][x+w]+num(px,py,x+w,y+h));
			}
		}
	}
	
	cout<<ret<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
