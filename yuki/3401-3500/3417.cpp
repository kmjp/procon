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

int N,S;
int A,B;
ll X[1010],W[1010],WS;
ll dp[1010][1010][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	int did=0;
	FOR(i,N) {
		cin>>X[i+did];
		if(did==0&&X[i]>S) {
			X[i+1]=X[i];
			X[i]=S;
			did=1;
		}
	}
	if(did==0) X[N]=S;
	did=0;
	FOR(i,N) {
		cin>>W[i+did];
		WS+=W[i+did];
		if(X[i]==S) {
			did=1;
			W[i+1]=W[i];
			W[i]=0;
		}
	}
	FOR(i,N+1) if(X[i]==S) r=i;
	FOR(x,N+2) FOR(y,N+2) dp[x][y][0]=dp[x][y][1]=1LL<<60;
	dp[r][r][0]=0;
	for(x=r;x>=0;x--) {
		ll wei=WS;
		for(i=x;i<r;i++) wei-=W[i];
		for(y=r;y<=N;y++) {
			wei-=W[y];
			if(x) {
				dp[x-1][y][0]=min(dp[x-1][y][0],dp[x][y][0]+(X[x]-X[x-1])*wei);
				dp[x-1][y][0]=min(dp[x-1][y][0],dp[x][y][1]+(X[y]-X[x-1])*wei);
			}
			if(y+1<=N) {
				dp[x][y+1][1]=min(dp[x][y+1][1],dp[x][y][0]+(X[y+1]-X[x])*wei);
				dp[x][y+1][1]=min(dp[x][y+1][1],dp[x][y][1]+(X[y+1]-X[y])*wei);
			}
		}
	}
	cout<<min(dp[0][N][0],dp[0][N][1])<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
