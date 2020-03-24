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


int N,S;
int A[3030];
const ll mo=998244353;
ll dp[3030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	dp[0]=0;
	ll ret=0;
	FOR(i,N) {
		cin>>x;
		for(j=S-x;j>=0;j--) {
			if(j==0) (dp[x]+=i+1)%=mo;
			else (dp[x+j]+=dp[j])%=mo;
		}
		ret+=dp[S];
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
