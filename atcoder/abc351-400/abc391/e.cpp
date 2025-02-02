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
string S;
int dp[9*9*9*9*9*9*3][3];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int M=1;
	FOR(i,N) M=M*3;
	cin>>S;
	FOR(i,M) {
		dp[i][0]=S[i]=='1';
		dp[i][1]=S[i]=='0';
		dp[i][2]=S[i]=='1';
	}
	while(M>1) {
		FOR(i,M/3) {
			dp[i][0]=min({dp[i*3][0]+dp[i*3+1][0],dp[i*3][0]+dp[i*3+2][0],dp[i*3+1][0]+dp[i*3+2][0]});
			dp[i][1]=min({dp[i*3][1]+dp[i*3+1][1],dp[i*3][1]+dp[i*3+2][1],dp[i*3+1][1]+dp[i*3+2][1]});
			dp[i][2]=(dp[i*3][2]+dp[i*3+1][2]+dp[i*3+2][2])/2;
		}
		M/=3;
	}
	cout<<dp[0][dp[0][2]^1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
