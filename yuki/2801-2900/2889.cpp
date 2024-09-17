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


int N;
int A[202020],B[202020],C[202020];
ll dp[202020][3][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) cin>>C[i];
	FOR(i,N) {
		FOR(j,3) FOR(k,3) for(x=j;x<3;x++) for(y=k;y<3;y++) {
			if(x==1&&y==1) dp[i+1][x][y]=max(dp[i+1][x][y],dp[i][j][k]+C[i]);
			if(x==1&&y!=1) dp[i+1][x][y]=max(dp[i+1][x][y],dp[i][j][k]+B[i]);
			if(x!=1&&y==1) dp[i+1][x][y]=max(dp[i+1][x][y],dp[i][j][k]+B[i]);
			if(x!=1&&y!=1) dp[i+1][x][y]=max(dp[i+1][x][y],dp[i][j][k]+A[i]);
		}
	}
	ll ret=0;
	FOR(x,3) FOR(y,3) ret=max(ret,dp[N][x][y]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
