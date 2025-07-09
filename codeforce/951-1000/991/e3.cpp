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

int T;
string A,B,C;
int X,Y,Z;
int dp[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C;
		X=A.size();
		Y=B.size();
		Z=C.size();
		FOR(x,X+1) FOR(y,Y+1) dp[x][y]=1<<20;
		dp[0][0]=0;
		FOR(x,X+1) FOR(y,Y+1) {
			if(x<X) dp[x+1][y]=min(dp[x+1][y],dp[x][y]+(A[x]!=C[x+y]));
			if(y<Y) dp[x][y+1]=min(dp[x][y+1],dp[x][y]+(B[y]!=C[x+y]));
		}
		cout<<dp[X][Y]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
