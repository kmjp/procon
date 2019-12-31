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

int N,X,Y;
int A[51],B[51];

int dp[52][10010];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	memset(dp,0xee,sizeof(dp));
	
	cin>>N>>X>>Y;
	dp[0][0]=0;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		for(j=50;j>=0;j--) {
			FOR(x,Y+1) if(dp[j][x]>=0) {
				y=x+B[i];
				z=A[i];
				if(y>Y) z+=y-Y, y=Y;
				dp[j+1][y]=max(dp[j+1][y],dp[j][x]+z);
			}
		}
	}
	FOR(i,51) if(dp[i][Y]>=X) return _P("%d\n",i);
	_P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
