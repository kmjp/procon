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
int D[20];
int dp[1<<17];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>D[i];
	
	memset(dp,0xcf,sizeof(dp));
	dp[0]=100;
	FOR(i,1<<N) {
		if(dp[i]<0) continue;
		int did=1;
		FOR(j,N) if((i&(1<<j)) && D[j]<0) did++;
		FOR(j,N) if((i&(1<<j))==0) {
			if(D[j]>0) dp[i+(1<<j)]=min(did*100,max(dp[i+(1<<j)],dp[i]+D[j]));
			else if(dp[i]+D[j]>0) dp[i+(1<<j)]=max(dp[i+(1<<j)],dp[i]+D[j]);
		}
	}
	cout<<max(0,dp[(1<<N)-1])<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
