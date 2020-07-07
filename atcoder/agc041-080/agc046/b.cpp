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

const ll mo=998244353;
int A,B,C,D;

ll dp[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D;
	
	dp[A][B]=1;
	for(x=A;x<=C;x++) {
		for(y=B;y<=D;y++) {
			dp[x][y]+=(dp[x-1][y]*y+dp[x][y-1]*x)%mo;
			dp[x][y]-=dp[x-1][y-1]*(x-1)*(y-1);
			dp[x][y]=(dp[x][y]%mo+mo)%mo;
		}
	}
	
	cout<<dp[C][D]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
