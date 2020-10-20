#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int X[20],Y[20],Z[20];
ll dp[1<<17][17];

int dif(int a,int b) {
	return abs(X[a]-X[b])+abs(Y[a]-Y[b])+max(0,Z[b]-Z[a]);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i]>>Z[i];
	FOR(i,N) FOR(j,1<<N) dp[j][i]=1LL<<60;
	dp[1][0]=0;
	int mask;
	FOR(mask,1<<N) {
		FOR(x,N) if(mask&(1<<x)) {
			FOR(y,N) dp[mask|(1<<y)][y]=min(dp[mask|(1<<y)][y],dp[mask][x]+dif(x,y));
		}
	}
	
	cout<<dp[(1<<N)-1][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
