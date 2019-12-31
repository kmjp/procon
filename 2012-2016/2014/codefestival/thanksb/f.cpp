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


string X,S,T;
ll dp[1003];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>X>>S>>T;
	
	dp[0]=1;
	FOR(i,X.size()) {
		if(i>=S.size()-1 && S==X.substr(i-(S.size()-1),S.size())) dp[i+1]+=dp[i-(S.size()-1)];
		if(i>=T.size()-1 && T==X.substr(i-(T.size()-1),T.size())) dp[i+1]+=dp[i-(T.size()-1)];
		dp[i+1]%=mo;
	}
	cout<<dp[X.size()]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
