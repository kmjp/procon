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
int A[16][16];
int B[15][15];
int C[15][15];

ll dp[1<<16][16]; //œ‚­—ñAs‚Ìmask,ÅŒã‚Ìs
ll dp2[16][16];
ll dp3[16][16];
ll difR[16][16][16];
ll difC[16][16][16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		ZERO(A);
		FOR(y,H) FOR(x,W) {
			cin>>A[y][x];
			A[H][x]^=A[y][x];
			A[y][W]^=A[y][x];
			A[H][W]^=A[y][x];
		}
		H++,W++;
		int y2,x2;
		FOR(y,H) FOR(y2,H) FOR(x,W) {
			difR[y][y2][x]=0;
			FOR(x2,W) if(x2!=x) difR[y][y2][x]+=abs(A[y][x2]-A[y2][x2]);
		}
		FOR(x,W) FOR(x2,W) FOR(y,H) {
			difC[x][x2][y]=0;
			FOR(y2,H) if(y2!=y) difC[x][x2][y]+=abs(A[y2][x]-A[y2][x2]);
		}
		
		int mask;
		FOR(i,16) FOR(j,16) dp2[i][j]=dp3[i][j]=1LL<<60;
		
		FOR(x,W) {
			FOR(j,16) FOR(mask,1<<H) dp[mask][j]=1LL<<60;
			FOR(y,H) dp[1<<y][y]=0;
			FOR(mask,1<<H) FOR(y,H) if(dp[mask][y]<1LL<<60) {
				FOR(y2,H) if((mask&(1<<y2))==0) chmin(dp[mask|(1<<y2)][y2],dp[mask][y]+difR[y][y2][x]);
			}
			FOR(y,H) FOR(y2,H) dp2[x][y]=min(dp2[x][y],dp[(1<<H)-1-(1<<y)][y2]);
		}
		FOR(y,H) {
			FOR(j,16) FOR(mask,1<<W) dp[mask][j]=1LL<<60;
			FOR(x,W) dp[1<<x][x]=0;
			FOR(mask,1<<W) FOR(x,W) if(dp[mask][x]<1LL<<60) {
				FOR(x2,W) if((mask&(1<<x2))==0) chmin(dp[mask|(1<<x2)][x2],dp[mask][x]+difC[x][x2][y]);
			}
			FOR(x,W) FOR(x2,W) dp3[y][x]=min(dp3[y][x],dp[(1<<W)-1-(1<<x)][x2]);
		}
		ll ret=1LL<<60;
		FOR(y,H) FOR(x,W) {
			ret=min(ret,dp2[x][y]+dp3[y][x]);
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
