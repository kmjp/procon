#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
ll S;
ll A[2020],B[2020];
ll C[2020],D[2020];
double dp[1717][1717];

int ok(double m) {
	int x,y,i;
	FOR(x,1515) FOR(y,1515) dp[x][y]=-1e15;
	dp[0][0]=S-m;
	FOR(x,N) {
		//
		FOR(y,K+1) {
			// remove
			if(y+D[x]<=K) dp[x+1][y+D[x]]=max(dp[x+1][y+D[x]],dp[x][y]);
		}
		FOR(y,K+1) {
			// inc
			dp[x+1][y]=max(dp[x+1][y],dp[x][y]+A[x]-m);
			// train
			if(y+C[x]<=K) dp[x][y+C[x]]=max(dp[x][y+C[x]],dp[x][y]+B[x]);
		}
	}
	
	FOR(i,K+1) if(dp[N][i]>=0) return 1;
	return 0;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FOR(i,N) cin>>A[i]>>B[i]>>C[i]>>D[i];
	double L=0,R=1e13;
	
	FOR(i,100) {
		double M=(L+R)/2;
		if(ok(M)) L=M;
		else R=M;
	}
	_P("%.12lf\n",L);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
