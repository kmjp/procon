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
int A[14];
int dp[1<<14];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ZERO(dp);
	FOR(i,N) cin>>A[i];
	dp[0]=0;
	for(int mask=0;mask<1<<N;mask++) if(dp[mask]>=0) {
		FOR(y,N) if((mask&(1<<y))==0) {
			FOR(x,y) if((mask&(1<<x))==0) {
				dp[mask|(1<<x)|(1<<y)]=max(dp[mask|(1<<x)|(1<<y)],dp[mask]+(A[x]^A[y]));
			}
		}
	}
	cout<<dp[(1<<N)-1]<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
