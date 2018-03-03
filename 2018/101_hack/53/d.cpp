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
int X[50505];
double S[50505],S2[50505];
double dp[50505][101];

double cost(int L,int R) {
	if(L>R) return 0;
	return (S2[R]-S2[L-1])-(S[R]-S[L-1])*(S[R]-S[L-1])/(R-L+1);
}

void hoge(int k,int CL,int CR,int PL,int PR) {
	if(CL>CR) return;
	int CM=(CL+CR)/2;
	int best=PL;
	for(int i=PL;i<=min(CM-1,PR);i++) {
		if(dp[i][k-1]+cost(i+1,CM)<dp[CM][k]) {
			dp[CM][k]=dp[i][k-1]+cost(i+1,CM);
			best=i;
		}
	}
	hoge(k,CL,CM-1,PL,best);
	hoge(k,CM+1,CR,best,PR);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>X[i+1];
	}
	sort(X+1,X+N+1);
	FOR(i,N) {
		S[i+1]=S[i]+X[i+1];
		S2[i+1]=S2[i]+1.0*X[i+1]*X[i+1];
	}
	
	for(i=0;i<=N;i++) for(j=0;j<=K;j++) dp[i][j]=1e15;
	dp[0][0]=0;
	for(i=1;i<=K;i++) hoge(i,1,N,0,N);
	_P("%.12lf\n",dp[N][K]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
