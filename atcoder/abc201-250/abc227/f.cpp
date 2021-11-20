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

int H,W,K;
int A[31][31];

ll dp[31][31][65];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	vector<int> V;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		V.push_back(A[y][x]);
	}
	ll mi=1LL<<60;
	FORR(v,V) {
		FOR(y,H+1) FOR(x,W+1) FOR(k,61) dp[y][x][k]=1LL<<60;
		if(A[0][0]>=v) dp[0][0][1]=A[0][0];
		else dp[0][0][0]=0;
		
		FOR(y,H) FOR(x,W) FOR(k,y+x+2) if(dp[y][x][k]<1LL<<60) {
			if(y+1<H) {
				if(A[y+1][x]<v) chmin(dp[y+1][x][k],dp[y][x][k]);
				else chmin(dp[y+1][x][k+1],dp[y][x][k]+A[y+1][x]);
			}
			if(x+1<W) {
				if(A[y][x+1]<v) chmin(dp[y][x+1][k],dp[y][x][k]);
				else chmin(dp[y][x+1][k+1],dp[y][x][k]+A[y][x+1]);
			}
		}
		for(k=K;k<=60;k++) mi=min(mi,dp[H-1][W-1][k]-1LL*(k-K)*v);
		
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
