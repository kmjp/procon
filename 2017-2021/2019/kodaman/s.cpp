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

int C[5],p,q;
ll dp[6][6100000];
ll S[6100000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,5) cin>>C[i];
	cin>>p>>q;
	if(60%q) return _P("0\n");
	p*=60/q;
	
	dp[0][0]=1;
	FOR(i,5) {
		x=60/(i+1);
		for(j=0;j<=6000000;j++) {
			S[j]=dp[i][j];
			if(j>=x) S[j]+=S[j-x];
			y=j-x*C[i];
			if(y-x<0) dp[i+1][j]=S[j];
			else dp[i+1][j]=S[j]-S[y-x];
		}
	}
	cout<<dp[5][p]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
