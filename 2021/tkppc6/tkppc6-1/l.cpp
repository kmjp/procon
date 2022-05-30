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

int N,M;
const ll mo=998244353;

ll dp[4020][2040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	dp[0][0]=1;
	FOR(i,2*N) {
		// all same
		
		(dp[i+2][0]+=dp[i][0])%=mo;
		(dp[i+2][2]+=mo-dp[i][0])%=mo;
		if(M%2==0) {
			(dp[i+1][0]+=dp[i][0])%=mo;
			(dp[i+1][2]+=dp[i][0])%=mo;
			(dp[i+1][M]+=2*(mo-dp[i][0]))%=mo;
		}
		else {
			(dp[i+1][1]+=2*dp[i][0])%=mo;
			(dp[i+1][M]+=2*(mo-dp[i][0]))%=mo;
		}
		
		for(x=1;x<M;x++) {
			// all same
			(dp[i+1][M-x]+=dp[i][x])%=mo;
			(dp[i+1][M-x+2]+=mo-dp[i][x])%=mo;
			
			int lef=M-(x+2);
			if(lef%2==0) {
				(dp[i+1][0]+=dp[i][x])%=mo;
				(dp[i+1][2]+=dp[i][x])%=mo;
			}
			else {
				(dp[i+1][1]+=2*dp[i][x])%=mo;
			}
			(dp[i+1][lef+2]+=2*(mo-dp[i][x]))%=mo;
		}
		
		for(x=2;x<M;x++) (dp[i+1][x]+=dp[i+1][x-2])%=mo;
		
	}
	cout<<dp[2*N][0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}