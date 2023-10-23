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

int N,K;
string S;

int dp[303][303];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	N=S.size();
	
	for(int len=0;len<=N;len++) {
		for(x=0;x+len<=N;x++) {
			dp[x][x+len]=len;
			for(y=x+1;y<x+len;y++) chmin(dp[x][x+len],dp[x][y]+dp[y][x+len]);
			if(S[x]=='o') {
				for(y=x+1;y<x+len;y++) if(dp[x+1][y]==0&&S[y]=='f') chmin(dp[x][x+len],max(0,dp[y+1][x+len]-K));
			}
		}
	}
	cout<<dp[0][N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
