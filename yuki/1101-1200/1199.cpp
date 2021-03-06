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

int H,W;
ll A[1010][1010];

ll dp[1010][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0]=0;
	dp[0][1]=-1LL<<60;
	
	cin>>H>>W;
	FOR(y,H) {
		ll V=0;
		FOR(x,W) {
			cin>>A[y][x];
			V+=A[y][x];
		}
		dp[y+1][0]=max(dp[y][0],dp[y][1]-V);
		dp[y+1][1]=max(dp[y][1],dp[y][0]+V);
	}
	cout<<dp[H][1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
