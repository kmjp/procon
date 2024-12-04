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

int N,X,P[101];

double dp[5050][5050];

double memo[5050];

double hoge(int X) {
	if(X<=0) return 0;
	if(memo[X]>=0) return memo[X];
	double ret=1/(1-dp[N][0]);
	
	int i;
	for(i=1;i<=N;i++) ret+=dp[N][i]/(1-dp[N][0])*hoge(X-i);
	return memo[X]=ret;
	
	
}
	
	

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	dp[0][0]=1;
	FOR(i,N) {
		cin>>x;
		FOR(j,N+1) {
			dp[i+1][j]+=dp[i][j]*(100-x)/100.0;
			dp[i+1][j+1]+=dp[i][j]*x/100.0;
		}
	}
	FOR(i,X+1) memo[i]=-1;
	
	_P("%.12lf\n",hoge(X));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
