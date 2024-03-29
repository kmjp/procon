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
int A[555][555];
int dp[555][555];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	vector<pair<int,int>> V;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		V.push_back({A[y][x],y*1000+x});
	}
	int ma=0;
	sort(ALL(V));
	FORR2(a,b,V) {
		y=b/1000;
		x=b%1000;
		dp[y][x]++;
		ma=max(ma,dp[y][x]);
		if(y&&A[y-1][x]>A[y][x]) chmax(dp[y-1][x],dp[y][x]);
		if(y+1<H&&A[y+1][x]>A[y][x]) chmax(dp[y+1][x],dp[y][x]);
		if(x&&A[y][x-1]>A[y][x]) chmax(dp[y][x-1],dp[y][x]);
		if(x+1<W&&A[y][x+1]>A[y][x]) chmax(dp[y][x+1],dp[y][x]);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
