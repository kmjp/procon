#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S;
double ret;
double dp[52][52][52];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	dp[0][0][0]=1;
	FOR(i,N) {
		FOR(x,N) FOR(y,N) {
			double cur=dp[i][x][y]*0.5;
			if(S[i]=='S') {
				// left
				if(y>0) dp[i+1][x][y-1] +=cur;
				else dp[i+1][x][y]+=cur, ret +=cur;
				
				// right
				dp[i+1][x+1][y] += cur;
			}
			else {
				// left
				if(x>0) dp[i+1][x-1][y] +=cur;
				else dp[i+1][x][y]+=cur, ret +=cur;
				
				// right
				dp[i+1][x][y+1] += cur;
			}
		}
	}
	FOR(x,N+1) FOR(y,N+1) ret += (x+y)*dp[N][x][y];
	
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
