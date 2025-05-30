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

int T,H,W;
int A[101][101];
int dp[101][101];

int ok(int v) {
	int y,x;
	FOR(y,H) FOR(x,W) dp[y][x]=0;
	dp[0][0]=1;
	FOR(y,H) FOR(x,W) {
		if(A[y][x]%v) dp[y][x]=0;
		if(dp[y][x]) {
			dp[y+1][x]=dp[y][x+1]=1;
		}
	}
	return dp[H-1][W-1];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) FOR(x,W) cin>>A[y][x];
		vector<int> cand;
		for(i=1;i*i<=A[0][0];i++) if(A[0][0]%i==0) {
			cand.push_back(i);
			cand.push_back(A[0][0]/i);
		}
		int ma=0;
		FORR(c,cand) if(ok(c)) ma=max(ma,c);
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
