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

int N,K;
ll mo;
ll dp[202][202];


ll hoge(int N,int K) {
	
	if(N==1) return 1;
	if(N==2) return 0;
	
	int x,y,k,l,i;
	ll ret=0;
	for(k=1;k<=N-2;k++) {
		l=N-1-k;
		if(k>K || l>K) continue;
		ZERO(dp);
		dp[0][0]=1;
		FOR(y,k+1) FOR(x,l+1) {
			if(y==0&&x==l) dp[y][x]=0;
			if(y-1+(l-x)>K) continue;
			if(x+(k-y)>K) continue;
			//cout<<y<<x<<" "<<dp[y][x]<<endl;
			(dp[y+1][x]+=dp[y][x])%=mo;
			(dp[y][x+1]+=dp[y][x])%=mo;
		}
		ret+=dp[k][l];
	}
	//cout<<N<<K<<" "<<ret<<endl;
	for(i=1;i<=N-1;i++) ret=ret*i%mo;
	//cout<<N<<K<<" "<<ret<<endl;
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>mo;
	
	ll ret=0;
	ll fac=1;
	while(2*K>=N-1) {
		ret+=fac*hoge(N,K)%mo;
		fac=fac*N%mo;
		N--,K--;
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
