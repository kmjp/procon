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

int dp[4030][4030];
int N,M;
vector<int> A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		A.push_back(0);
		FOR(j,x) A.push_back(1);
	}
	N=A.size();
	FOR(i,M) {
		cin>>x;
		B.push_back(0);
		FOR(j,x) B.push_back(1);
	}
	M=B.size();
	
	FOR(x,N+2) FOR(y,M+2) dp[x][y]=1<<30;
	dp[0][0]=0;
	FOR(x,N+1) FOR(y,M+1) if(dp[x][y]<1<<30) {
		int r=dp[x][y];
		chmin(dp[x+1][y],r+1);
		chmin(dp[x][y+1],r+1);
		chmin(dp[x+1][y+1],r+1);
		if(x<N&&y<M&&A[x]==B[y]) chmin(dp[x+1][y+1],r);
	}
	cout<<dp[N][M]<<endl;
	
}
	

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
