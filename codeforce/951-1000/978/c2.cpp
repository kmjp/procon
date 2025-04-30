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

int T,N;
string A,B;
int dp[101010][5];
int X[202020],Y[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B;
		FOR(i,N+2) FOR(j,5) dp[i][j]=-1;
		FOR(i,N) X[i]=A[i]=='A';
		FOR(i,N) Y[i]=B[i]=='A';
		dp[0][2]=0;
		
		FOR(i,N) {
			if(dp[i][0]>=0) {
				chmax(dp[i+2][3],dp[i][0]+(Y[i]+Y[i+1]+Y[i+2]>=2));
			}
			if(dp[i][1]>=0) {
				chmax(dp[i+1][4],dp[i][1]+(Y[i]+Y[i+1]+Y[i+2]>=2));
				chmax(dp[i+2][2],dp[i][1]+(Y[i]+Y[i+1]+X[i+1]>=2));
			}
			if(dp[i][2]>=0) {
				chmax(dp[i+3][2],dp[i][2]+(Y[i]+Y[i+1]+Y[i+2]>=2)+(X[i]+X[i+1]+X[i+2]>=2));
				chmax(dp[i+1][1],dp[i][2]+(Y[i]+X[i]+X[i+1]>=2));
				chmax(dp[i+1][3],dp[i][2]+(Y[i]+Y[i+1]+X[i]>=2));
			}
			if(dp[i][3]>=0) {
				chmax(dp[i+1][0],dp[i][3]+(X[i]+X[i+1]+X[i+2]>=2));
				chmax(dp[i+2][2],dp[i][3]+(X[i]+X[i+1]+Y[i+1]>=2));
			}
			if(dp[i][4]>=0) {
				chmax(dp[i+2][1],dp[i][4]+(X[i]+X[i+1]+X[i+2]>=2));
			}
			
		}
		cout<<dp[N][2]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
