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
ll dp[101010][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		if(i==0) {
			cin>>dp[i][0]>>dp[i][1]>>dp[i][2];
		}
		else {
			int X[3];
			cin>>X[0]>>X[1]>>X[2];
			dp[i][0]=max({dp[i-1][1]+X[0],dp[i-1][2]+X[0]});
			dp[i][1]=max({dp[i-1][0]+X[1],dp[i-1][2]+X[1]});
			dp[i][2]=max({dp[i-1][0]+X[2],dp[i-1][1]+X[2]});
		}
	}
	cout<<max({dp[N-1][0],dp[N-1][1],dp[N-1][2]})<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
