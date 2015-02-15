#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
double dp[10000];

double test(double d) {
	int i,j;
	
	
	for(i=1;i<=N;i++) {
		for(j=1;j<=6;j++) {
			if(j>i) if(j>i) dp[i] += d;
			if(i>j) dp[i] += dp[i-j];
		}
		dp[i]=dp[i]/6.0+1;
	}
	return dp[N];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	double L=0,R=1e10;
	FOR(i,100) {
		double M=(L+R)/2.0;
		if(test(M)>=M) L=M;
		else R=M;
	}
	_P("%.12lf\n",(L+R)/2.0);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
