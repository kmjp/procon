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
string S;
ll dp[4040][8];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0]=1;
	
	cin>>N>>S;
	
	FORR(c,S) {
		if(c=='R') c=0;
		if(c=='G') c=1;
		if(c=='B') c=2;
	}
	
	FOR(i,N) {
		FOR(j,8) {
			dp[i+1][j]+=dp[i][j];
			if((j&(1<<S[i]))==0) dp[i+1][j|(1<<S[i])]+=dp[i][j];
		}
	}
	ll ret=dp[N][7];
	FOR(i,N) {
		for(j=1;j<=N;j++) {
			x=i-j;
			y=i+j;
			if(x<0 || y>=N) break;
			if(S[i]!=S[x]&&S[i]!=S[y]&&S[x]!=S[y]) ret--;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
