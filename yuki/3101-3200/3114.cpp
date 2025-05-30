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
int dp[202020][2][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	if(S=="0"||S=="00") {
		cout<<1<<endl;
		return;
	}
	if(N<=2) {
		cout<<0<<endl;
		return;
	}
	dp[1][1][0]=(S[0]!='1')+(S[1]!='0');
	dp[1][1][1]=(S[0]!='1')+(S[1]!='1');
	dp[1][0][1]=(S[0]!='0')+(S[1]!='1');
	
	for(i=2;i<N;i++) {
		FOR(x,2) FOR(y,2) FOR(k,2) dp[i][y][k]=1<<30;
		FOR(x,2) FOR(y,2) FOR(k,2) {
			if(x+y+k<=1) continue;
			dp[i][y][k]=min(dp[i][y][k],dp[i-1][x][y]+((S[i]-'0')!=k));
		}
	}
	int ret=min({dp[N-1][0][1],dp[N-1][1][0],dp[N-1][1][1]});
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
