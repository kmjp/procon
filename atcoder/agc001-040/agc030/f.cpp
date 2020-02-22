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
int L;
int used[606];
ll dp[606][306][306];
ll mo=1000000007;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	L=2*N;
	
	int F=0;
	FOR(i,N) {
		cin>>x>>y;
		if(x>y) swap(x,y);
		
		if(y==-1) {
			F++;
		}
		else if(x==-1 && y!=-1) {
			used[y]=1;
		}
		else if(x>-1) {
			used[x]=used[y]=2;
		}
	}
	
	dp[L][0][0]=1;
	for(i=L;i>=1;i--) FOR(x,N+1) FOR(y,N+1) {
		ll v=dp[i][x][y];
		if(v==0) continue;
		
		if(used[i]==2) {
			(dp[i-1][x][y]+=v)%=mo;
		}
		else if(used[i]==1) {
			(dp[i-1][x][y+1]+=v)%=mo;
			if(x) (dp[i-1][x-1][y]+=v)%=mo;
		}
		else {
			(dp[i-1][x+1][y]+=v)%=mo;
			if(x) (dp[i-1][x-1][y]+=v)%=mo;
			if(y) (dp[i-1][x][y-1]+=v*y)%=mo;
		}
	}
	
	ll ret=dp[0][0][0];
	while(F) ret=ret*(F--)%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
