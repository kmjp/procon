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


int N,num;
string S;
ll dp[4];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	cin>>N>>S;
	
	dp[0]=1;
	FORR(c,S) {
		if(c=='a') {
			(dp[1]+=dp[0])%=mo;
		}
		else if(c=='b') {
			(dp[2]+=dp[1])%=mo;
		}
		else if(c=='c') {
			(dp[3]+=dp[2])%=mo;
		}
		else {
			(dp[3]=dp[3]*3+dp[2])%=mo;
			(dp[2]=dp[2]*3+dp[1])%=mo;
			(dp[1]=dp[1]*3+dp[0])%=mo;
			dp[0]=dp[0]*3%mo;
		}
	}
	
	cout<<dp[3]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
