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
int X[15],Y[15];
double D[15][15];
double dp[1<<15][15];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
	}
	FOR(y,N) FOR(x,N) D[x][y]=hypot(X[x]-X[y],Y[x]-Y[y]);
	int mask;
	FOR(mask,1<<15) FOR(i,N) dp[mask][i]=1e9;
	dp[0][0]=0;
	FOR(mask,1<<N) FOR(i,N) {
		FOR(j,N) chmin(dp[mask|(1<<j)][j],dp[mask][i]+D[i][j]);
	}
	_P("%.12lf\n",dp[(1<<N)-1][0]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
