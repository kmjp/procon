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

int N,M;
int H[202020];

vector<int> X[202020];
vector<int> Y[202020];

ll dp[202020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>H[i];
	FOR(i,M) {
		cin>>x>>y;
		X[x-1].push_back(y-1);
		Y[y-1].push_back(x-1);
	}
	
	FOR(i,N) dp[i][0]=dp[i][1]=-1LL<<60;
	dp[0][0]=0;
	FOR(i,N) {
		FORR(e,X[i]) {
			if(H[e]>H[i]) {
				dp[e][1]=max(dp[e][1],dp[i][0]+H[e]-H[i]);
			}
			if(H[e]<H[i]) {
				dp[e][0]=max(dp[e][0],dp[i][0]);
				dp[e][0]=max(dp[e][0],dp[i][1]);
			}
		}
	}
	ll ret=max(dp[N-1][0],dp[N-1][1]);
	if(ret<=-1LL<<59) ret=-1;
	cout<<ret<<endl;
	
	FOR(i,N) dp[i][0]=dp[i][1]=-1LL<<60;
	dp[N-1][0]=0;
	for(i=N-1;i>=0;i--) {
		FORR(e,Y[i]) {
			if(H[e]>H[i]) {
				dp[e][1]=max(dp[e][1],dp[i][0]+H[e]-H[i]);
			}
			if(H[e]<H[i]) {
				dp[e][0]=max(dp[e][0],dp[i][0]);
				dp[e][0]=max(dp[e][0],dp[i][1]);
			}
		}
	}
	ret=max(dp[0][0],dp[0][1]);
	if(ret<=-1LL<<59) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
