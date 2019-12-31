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

int H,W,K;

int NG[2020][2020];
ll dp[2020][2020];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	H--,W--;
	FOR(i,K) {
		cin>>x>>y;
		x--,y--;
		r=x+y+1;
		FOR(j,r+1) if(j!=x&&j!=x+1) NG[j][r-j]=1;
	}
	
	dp[0][0]=1;
	FOR(y,H+1) FOR(x,W+1) if((x||y) && NG[x][y]==0) {
		if(x) dp[x][y]+=dp[x-1][y];
		if(y) dp[x][y]+=dp[x][y-1];
		dp[x][y]%=mo;
	}
	cout<<dp[W][H]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
