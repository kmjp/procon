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

string N;
const ll mo=998244353;

ll dp[1010101][3][3][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	dp[0][2][2][0]=1;
	FOR(i,N.size()) {
		FOR(x,3) FOR(y,3) FOR(k,10) {
			int P[]={0,2,2,2,1,2,2,2,2,2,2,2};
			int v=P[k];
			if(x==1&&y==0&&v==1) continue;
			(dp[i+1][v][y][1]+=dp[i][y][x][1])%=mo;
			if(k==N[i]-'0') (dp[i+1][v][y][0]+=dp[i][y][x][0])%=mo;
			if(k<N[i]-'0') (dp[i+1][v][y][1]+=dp[i][y][x][0])%=mo;
		}
	}
	ll ret=mo-1;
	FOR(x,3) FOR(y,3) ret+=dp[N.size()][x][y][0]+dp[N.size()][x][y][1];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
