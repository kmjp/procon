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

int N,X[18],Y[18];
ll L[2][18][18];
ll dp[1<<18][18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X[N+1]>>Y[N+1];
	X[0]=Y[0]=1;
	FOR(i,N) cin>>X[i+1]>>Y[i+1];
	
	FOR(x,18) FOR(y,18) {
		L[0][x][y]=abs(X[x]-X[y])+abs(Y[x]-Y[y]);
		L[1][x][y]=max(abs(X[x]-X[y]),abs(Y[x]-Y[y]));
	}
	N++;
	int mask;
	FOR(mask,2<<N) FOR(i,N+1) dp[mask][i]=1LL<<60;
	dp[1][0]=0;
	ll ret=1LL<<60;
	FOR(mask,2<<N) FOR(x,N+1) {
		FOR(y,N+1) {
			if(mask&(1<<N)) chmin(dp[mask|(1<<y)][y],dp[mask][x]+L[1][x][y]);
			else chmin(dp[mask|(1<<y)][y],dp[mask][x]+L[0][x][y]);
			
		}
		if((mask&((1<<N)-1))==(1<<N)-1) ret=min(ret,dp[mask][x]);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
