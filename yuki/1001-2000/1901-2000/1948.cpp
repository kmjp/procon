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

int H,W;
ll A[555][555];
ll dp[555][555][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	dp[0][0][0]=A[0][0];
	A[0][0]=0;
	FOR(y,H) FOR(x,W) {
		if(dp[y][x][0]>A[y][x]) {
			if(y+1<H) dp[y+1][x][0]=max(dp[y+1][x][0],dp[y][x][0]+A[y][x]);
			if(x+1<W) dp[y][x+1][0]=max(dp[y][x+1][0],dp[y][x][0]+A[y][x]);
			if(y==H-1&&x==W-1) {
				cout<<"Yes"<<endl;
				return;
			}
		}
		else {
			if(y+1<H) dp[y+1][x][1]=max(dp[y+1][x][1],dp[y][x][0]);
			if(x+1<W) dp[y][x+1][1]=max(dp[y][x+1][1],dp[y][x][0]);
		}
		if(dp[y][x][1]>A[y][x]) {
			if(y+1<H) dp[y+1][x][1]=max(dp[y+1][x][1],dp[y][x][1]+A[y][x]);
			if(x+1<W) dp[y][x+1][1]=max(dp[y][x+1][1],dp[y][x][1]+A[y][x]);
			if(y==H-1&&x==W-1) {
				cout<<"Yes"<<endl;
				return;
			}
		}
		
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
