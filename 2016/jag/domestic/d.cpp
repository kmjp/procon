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

int N,M;
int A[51],B[51];
int memo[52][52][52][52][2][2];

int dp(int ta,int tb,int sa,int sb,int turn,int pp) {
	if(pp==2) return 0;
	if(memo[ta][tb][sa][sb][turn][pp]!=1<<30) return memo[ta][tb][sa][sb][turn][pp];
	int i;
	int ret=0;
	if(turn==0) {
		ret=-1<<30;
		// stack
		if(ta!=N) {
			if(A[ta]==-1) {
				ret=dp(ta+1,tb,sa,tb,1,0);
			}
			else {
				ret=dp(ta+1,tb,sa,sb,1,0);
			}
		}
		
		// take
		if(sa!=ta || sb!=tb) {
			int hoge=0;
			for(i=sa;i<ta;i++) hoge+=(A[i]!=-1)?A[i]:0;
			for(i=sb;i<tb;i++) hoge-=(B[i]!=-1)?B[i]:0;
			ret=max(ret,hoge+dp(ta,tb,ta,tb,1,0));
		}
		else {
			ret=max(ret,dp(ta,tb,ta,tb,1,pp+1));
		}
		
	}
	else{
		ret=1<<30;
		// stack
		if(tb!=M) {
			if(B[tb]==-1) {
				ret=dp(ta,tb+1,ta,sb,0,0);
			}
			else {
				ret=dp(ta,tb+1,sa,sb,0,0);
			}
		}
		// take
		if(sa!=ta || sb!=tb) {
			int hoge=0;
			for(i=sa;i<ta;i++) hoge+=(A[i]!=-1)?A[i]:0;
			for(i=sb;i<tb;i++) hoge-=(B[i]!=-1)?B[i]:0;
			ret=min(ret,hoge+dp(ta,tb,ta,tb,0,0));
		}
		else {
			ret=min(ret,dp(ta,tb,ta,tb,0,pp+1));
		}
	}
	return memo[ta][tb][sa][sb][turn][pp]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,M) cin>>B[i];
	FOR(i,N+1) FOR(j,M+1) FOR(x,N+1) FOR(y,M+1) {
		memo[i][j][x][y][0][0]=memo[i][j][x][y][0][1]=1<<30;
		memo[i][j][x][y][1][0]=memo[i][j][x][y][1][1]=1<<30;
	}
	
	cout<<dp(0,0,0,0,0,0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
