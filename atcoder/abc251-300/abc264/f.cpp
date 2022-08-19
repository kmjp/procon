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
int R[20202],C[2020];
int A[2020][2020];
ll dp[2020][2020][2][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>R[y];
	FOR(x,W) cin>>C[x];
	FOR(y,H) {
		cin>>s;
		FOR(x,W) A[y][x]=s[x]=='1';
	}
	
	FOR(y,H) FOR(x,W) {
		dp[y][x][0][0]=dp[y][x][1][1]=dp[y][x][0][1]=dp[y][x][1][0]=1LL<<60;
	}
	dp[0][0][0][0]=0;
	dp[0][0][1][0]=R[0];
	dp[0][0][0][1]=C[0];
	dp[0][0][1][1]=R[0]+C[0];
	
	FOR(y,H) FOR(x,W) {
		int r,c;
		FOR(r,2) FOR(c,2) {
			if(y+1<H) {
				if((A[y][x]^r^c)==(A[y+1][x]^c)) {
					dp[y+1][x][0][c]=min(dp[y+1][x][0][c],dp[y][x][r][c]);
				}
				else {
					dp[y+1][x][1][c]=min(dp[y+1][x][1][c],dp[y][x][r][c]+R[y+1]);
				}
			}
			if(x+1<W) {
				if((A[y][x]^r^c)==(A[y][x+1]^r)) {
					dp[y][x+1][r][0]=min(dp[y][x+1][r][0],dp[y][x][r][c]);
				}
				else {
					dp[y][x+1][r][1]=min(dp[y][x+1][r][1],dp[y][x][r][c]+C[x+1]);
				}
			}
			
		}
	}
	ll ret=min({dp[H-1][W-1][0][0],dp[H-1][W-1][0][1],dp[H-1][W-1][1][0],dp[H-1][W-1][1][1]});
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
