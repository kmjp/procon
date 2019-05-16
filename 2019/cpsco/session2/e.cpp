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
int P[5050];
ll H[5050];
int C[5050];
ll dp[5050][5050];
vector<int> E[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(x,N+1) FOR(y,N+1) dp[x][y]=1LL<<60;
	FOR(i,N-1) {
		cin>>P[i+1]>>H[i+1];
		E[P[i+1]].push_back(i+1);
	}
	
	for(i=N-1;i>=0;i--) {
		dp[i][0]=0;
		FORR(e,E[i]) {
			for(x=C[i];x>=0;x--) {
				for(y=C[e];y>=0;y--) {
					dp[i][x+y]=min(dp[i][x+y],dp[i][x]+dp[e][y]);
				}
			}
			C[i]+=C[e];
		}
		if(i) {
			for(x=C[i];x>=0;x--) {
				if(dp[i][x]<=H[i]) dp[i][x+1]=min(dp[i][x+1],H[i]);
				else dp[i][x]=1LL<<60;
			}
		}
		C[i]++;
	}
	
	for(x=N;x>=0;x--) {
		if(dp[0][x]<1LL<<60) {
			cout<<x+1<<endl;
			break;
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
