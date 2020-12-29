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
string S,T;

int dp[101][101];
int del[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	
	for(int len=0;len<=N;len+=3) {
		for(x=0;x+len<=N;x++) {
			if(len==0) del[x][x+len]=1;
			else {
				for(y=3;y<len;y+=3) del[x][x+len]|=del[x][x+y]&del[x+y][x+len];
				for(y=x+1;y<x+len-1;y++) if(S[x]==T[0]&&S[y]==T[1]&&S[x+len-1]==T[2]&&del[x+1][y]&&del[y+1][x+len-1]) del[x][x+len]=1;
			}
			if(del[x][x+len]) dp[x][x+len]=len/3;
		}
	}
	for(int len=1;len<=N;len++) {
		for(x=0;x+len<=N;x++) {
			for(y=x+1;y<x+len;y++) dp[x][x+len]=max(dp[x][x+len],dp[x][y]+dp[y][x+len]);
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
