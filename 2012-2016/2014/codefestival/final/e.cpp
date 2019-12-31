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
int R[3305];
int dp[3005][2];
int ma;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>R[i];
	
	FOR(x,N) {
		dp[x+1][0]=dp[x+1][1]=1;
		FOR(y,x) {
			if(R[y]<R[x]) dp[x+1][1]=max(dp[x+1][1],dp[y+1][0]+1);
			if(R[y]>R[x]) dp[x+1][0]=max(dp[x+1][0],dp[y+1][1]+1);
		}
		ma=max(ma,dp[x+1][0]);
		ma=max(ma,dp[x+1][1]);
	}
	
	if(ma<3) ma=0;
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
