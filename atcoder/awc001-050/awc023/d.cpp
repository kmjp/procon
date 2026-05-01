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

int N,S,T;
ll dp[51][10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	FOR(x,N+1) FOR(y,S+1) dp[x][y]=-1LL<<60;
	dp[0][0]=0;
	FOR(i,N) {
		int P,C,W;
		cin>>P>>C>>W;
		for(x=N-1;x>=0;x--) {
			for(y=0;y+W<=S;y++) dp[x+1][y+W]=max(dp[x+1][y+W],dp[x][y]+P-C);
		}
	}
	int mi=100;
	FOR(x,N+1) FOR(y,S+1) if(dp[x][y]>=T) mi=min(mi,x);
	if(mi==100) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
