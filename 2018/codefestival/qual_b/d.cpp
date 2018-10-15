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

int N,M,Q;
int X[2020];
long double P[2020];
long double PS[2020];

long double dp[2020][2020];

static const int N_=2020;
static long double C_[N_][N_];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,N_) C_[i][0]=C_[i][i]=1;
	for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>X[i]>>P[i];
		P[i]/=Q;
		PS[i+1]=PS[i]+P[i];
	}
	
	for(i=M-1;i>=0;i--) for(x=N;x>=0;x--) dp[i][x]=C_[N][x]*pow(PS[i+1],x)*pow(1-PS[i+1],N-x);
	FOR(i,M) for(x=N;x>=0;x--) dp[i][x]+=dp[i][x+1];
	for(i=M-1;i>=1;i--) for(x=N;x>=0;x--) dp[i][x]-=dp[i-1][x];
	
	
	long double ret=0;
	for(i=1;i<=N;i++) {
		long double S[2020]={};
		long double PS[2020]={};
		FOR(j,M) {
			S[j+1]=S[j]+X[j]*dp[j][i];
			PS[j+1]=PS[j]+dp[j][i];
			
		}
		long double be=1e10;
		FOR(j,M) {
			be=min(be,(S[M]-S[j+1])-X[j]*(1-PS[j+1])+X[j]*PS[j]-S[j]);
		}
		
		ret+=be;
	}
	_P("%.12lf\n",(double)ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
