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

int P,Q;

double dp[1010][101];

double R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>Q;
	dp[0][P]=R=1/3.0;
	
	FOR(i,1001) {
		FOR(j,101) if(dp[i][j]) {
			R += dp[i][j]*(j/100.0)/2.0;
			R += dp[i][j]*(1-(j/100.0))/3.0;
			dp[i+1][min(j+Q,100)] += dp[i][j]*(1-(j/100.0))/3.0;
			dp[i+1][max(j-Q,0)] += dp[i][j]*(j/100.0)/2.0;
		}
	}
	
	_P("%.12lf\n",R);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
