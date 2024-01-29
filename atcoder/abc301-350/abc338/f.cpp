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
ll E[22][22];
ll dp[1<<20][20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) E[x][y]=(x==y)?0:1LL<<60;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1][y-1]=k;
	}
	FOR(i,N) FOR(k,N) FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][k]+E[k][y]);
	
	int mask;
	FOR(mask,1<<N) FOR(i,N) dp[mask][i]=1LL<<60;
	FOR(i,N) dp[1<<i][i]=0;
	FOR(mask,1<<N) FOR(x,N) if((mask&(1<<x))&&dp[mask][x]<1LL<<60) {
		FOR(y,N) if((mask&(1<<y))==0) chmin(dp[mask|(1<<y)][y],dp[mask][x]+E[x][y]);
	}
	
	ll ret=1LL<<60;
	FOR(i,N) ret=min(ret,dp[(1<<N)-1][i]);
	if(ret>=1LL<<50) {
		cout<<"No"<<endl;
	}
	else {
		cout<<ret<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
