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
int A[202020];

int dp[202020][2][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N+1) {
		FOR(x,2) FOR(y,2) dp[i][x][y]=-1<<20;
	}
	dp[0][0][0]=0;
	int sum=0;
	FOR(i,N) {
		cin>>A[i];
		sum+=A[i];
		FOR(x,2) FOR(y,2) FOR(k,2) {
			if(A[i]==1&&k==0) continue;
			if(x+y+k!=3) dp[i+1][y][k]=max(dp[i+1][y][k],dp[i][x][y]+k);
		}
	}
	cout<<max({dp[N][0][0],dp[N][0][1],dp[N][1][0],dp[N][1][1]})-sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
