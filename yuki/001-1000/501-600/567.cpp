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

int N;
double dp[1010101][7];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0]=1;
	cin>>N;
	FOR(i,1010000) {
		FOR(j,7) {
			if(j==6) dp[i+1][j]+=dp[i][j];
			else {
				dp[i+1][j+1] += dp[i][j]*(6.0-j)/6.0;
				dp[i+1][j] +=   dp[i][j]*j/6.0;
			}
		}
	}
	_P("%.12lf\n",dp[N][6]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
