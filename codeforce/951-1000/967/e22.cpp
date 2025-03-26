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

int T,N,K;
ll mo;

ll memo[105][505];
ll memo2[105][505];
ll dp[105][505][505];
ll dp2[505][505];
ll dp3[505][505];
ll p2[505];

ll G(int N,int M);
ll F(int N,int M) {  // left most‚ª––”ö‚Ü‚Ås‚­
	if(N==1) return 1;
	if(M==0) return 0;
	if(memo[N][M]>=0) return memo[N][M];
	__int128 ret=F(N,M-1);
	
	int x,y;
	for(x=0;x<=M;x++) if(x*2>M) (ret+=F(N-1,x)*G(N-1,M-x));
	
	return memo[N][M]=ret%mo;
	
}

ll G(int N,int M) {  // ––”ö‚Ü‚Ås‚©‚È‚¢
	if(N==1||M==0) return 1;
	if(memo2[N][M]>=0) return memo2[N][M];
	__int128 ret=G(N,M-1);
	
	int x,y;
	for(x=0;x<=M;x++) (ret+=G(N-1,x)*G(N-1,M-x));
	
	return memo2[N][M]=ret%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>mo;
		
		p2[0]=1;
		FOR(i,N+1) p2[i+1]=p2[i]*2%mo;
		
		MINUS(memo);
		MINUS(memo2);
		FOR(i,N+2) FOR(x,K+2) FOR(y,K+2) dp[i][x][y]=0;
		FOR(x,K+1) FOR(y,x) if(x+y<=K) dp[1][x][y]=1;
		
		for(i=2;i<N;i++) {
			ZERO(dp2);
			ZERO(dp3);
			for(int l2=0;l2<=K;l2++) for(int r2=0;r2<l2&&l2+r2<=K;r2++) {
				(dp2[min(K+1,l2+r2)][l2+1]+=F(i-1,l2)*G(i-1,r2))%=mo;
			}
			
			for(int l2=1;l2<=K;l2++) for(int r2=0;r2<l2&&l2+r2<=K;r2++) {
				(dp3[min(K+1,l2+r2)][l2-1]+=dp[i-1][l2][r2])%=mo;
			}
			
			FOR(x,K+1) {
				for(y=K;y>=0;y--) {
					if(x) dp3[x][y]+=dp3[x-1][y];
					dp3[x][y]+=dp3[x][y+1];
					if(x) dp3[x][y]+=mo-dp3[x-1][y+1];
					dp3[x][y]%=mo;
				}
				FOR(y,K+1) {
					if(x) dp2[x][y]+=dp2[x-1][y];
					if(y) dp2[x][y]+=dp2[x][y-1];
					if(x&&y) dp2[x][y]+=mo-dp2[x-1][y-1];
					dp2[x][y]%=mo;
					if(x>y) dp[i][x][y]=(dp2[x][y]*F(i,y)%mo*p2[i-1]+dp3[x][y]*G(i,y))%mo;
				}
			}
			
		}
		
		ll ret=0;
		for(int l=0;l<=K;l++) for(int r=0;l+r<=K;r++) ret+=dp[N-1][l][r];
		ret=ret%mo*p2[N-1]%mo;
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
