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

int N,M,X,K;
int P[5050];
vector<int> V[5050];

ll dp[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X>>K;
	FOR(i,X) cin>>P[i];
	FOR(i,N) {
		cin>>x>>y>>j;
		V[j-1].push_back(max(0,P[x-1]-y));
	}
	FOR(i,N+1) dp[i]=1LL<<60;
	dp[0]=0;
	FOR(i,M) if(V[i].size()) {
		sort(ALL(V[i]));
		for(x=N;x>=0;x--) if(dp[x]<1LL<<60) {
			for(y=1;y<=V[i].size()&&x+y<=N;y++) dp[x+y]=min(dp[x+y],dp[x]+V[i][y-1]);
		}
	}
	
	cout<<dp[K]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
