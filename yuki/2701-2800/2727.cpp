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
ll P[3][3];
int dp[10101][102][2][2];
int A[10101];
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(y,3) FOR(x,3) cin>>P[y][x];
		FOR(i,N) cin>>A[i];
		cin>>S;
		
		FOR(i,101) {
			dp[N][i][0][0]=-1;
			dp[N][i][0][1]=-1;
			dp[N][i][1][0]=-1;
			dp[N][i][1][1]=(i>=K);
		}
		for(i=N-1;i>=0;i--) {
			FOR(j,101) FOR(x,2) FOR(y,2) {
				// 1”{
				set<int> R;
				R.insert(dp[i+1][j][x][y]);
				int nj=(A[i]+1);
				int nx=x;
				int ny=y;
				if(nx==0&&nj%2==0) nx=1,nj/=2;
				if(ny==0&&nj%3==0) ny=1,nj/=3;
				nj=nj*j%101;
				R.insert(dp[i+1][nj][nx][ny]);
				
				if(S[i]=='K') {
					if(R.count(1)) dp[i][j][x][y]=1;
					else if(R.count(-1)) dp[i][j][x][y]=-1;
					else dp[i][j][x][y]=0;
				}
				else {
					if(R.count(0)) dp[i][j][x][y]=0;
					else if(R.count(-1)) dp[i][j][x][y]=-1;
					else dp[i][j][x][y]=1;
				}
			}
		}
		ll d=P[0][0]*P[1][1]*P[2][2]+P[0][1]*P[1][2]*P[2][0]+P[0][2]*P[1][0]*P[2][1];
		d-=P[0][0]*P[1][2]*P[2][1]+P[0][1]*P[1][0]*P[2][2]+P[0][2]*P[1][1]*P[2][0];
		d=abs(d);
		x=y=0;
		
		if(d==0) {
			cout<<"D"<<endl;
			continue;
		}
		
		if(d%2==0) d/=2,x=1;
		if(d%3==0) d/=3,y=1;
		d%=101;
		if(dp[0][d][x][y]==1) cout<<"K"<<endl;
		if(dp[0][d][x][y]==0) cout<<"P"<<endl;
		if(dp[0][d][x][y]==-1) cout<<"D"<<endl;
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
