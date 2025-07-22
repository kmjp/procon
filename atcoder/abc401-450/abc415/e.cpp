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
vector<int> A[202020];
vector<ll> dp[202020];
ll P[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		FOR(x,W) {
			cin>>k;
			A[y].push_back(k);
			dp[y].push_back(0);
		}
	}
	FOR(i,H+W-1) cin>>P[i];
	
	ll ret=(1LL<<60)-1;
	for(i=59;i>=0;i--) {
		FOR(y,H) FOR(x,W) dp[y][x]=-1LL<<60;
		dp[0][0]=ret-(1LL<<i);
		FOR(y,H) FOR(x,W) {
			dp[y][x]+=A[y][x];
			dp[y][x]-=P[y+x];
			if(dp[y][x]>=0) {
				if(y+1<H) dp[y+1][x]=max(dp[y+1][x],dp[y][x]);
				if(x+1<W) dp[y][x+1]=max(dp[y][x+1],dp[y][x]);
			}
		}
		
		
		if(dp[y-1][x-1]>=0) ret-=1LL<<i;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
