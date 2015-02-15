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

int N,K;
double dp[2][300][300];
double p;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	if(K==1) dp[0][0][K]=1;
	else dp[0][K][0]=1;
	
	FOR(i,N) {
		int cur=i%2,tar=cur^1;
		cin>>x;
		p=x*0.01;
		ZERO(dp[tar]);
		
		FOR(x,K+1) FOR(y,K+1) {
			
			//ts
			if(y>0) dp[tar][x][y-1] += p*dp[cur][x][y];
			else if(x==2) dp[tar][0][y+1] += p*dp[cur][x][y];
			else if(x>2) dp[tar][x-1][y] += p*dp[cur][x][y];
			else dp[tar][x][y] += p*dp[cur][x][y];
			
			//ys
			if(K==1 && y==1) dp[tar][0][0] += (1-p)*dp[cur][x][y];
			else if(x==K) {
				if(K==1) dp[tar][0][0] += (1-p)*dp[cur][x][y];
				if(K==2) dp[tar][0][1] += (1-p)*dp[cur][x][y];
				else dp[tar][K-1][0] += (1-p)*dp[cur][x][y];
			}
			else if(x==2) dp[tar][0][y+1] += (1-p)*dp[cur][x][y];
			else if(x==3) dp[tar][0][y+2] += (1-p)*dp[cur][x][y];
			else if(x>3) dp[tar][x-2][y+1] += (1-p)*dp[cur][x][y];
			else dp[tar][x][y] += (1-p)*dp[cur][x][y];
		}
	}
	
	double ret=0;
	FOR(x,K+1) FOR(y,K+1) ret += dp[N%2][x][y]*(x+y);
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
