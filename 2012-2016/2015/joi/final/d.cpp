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

int N,M,TN;
int P[101010],D[101010];
int dp[202020];
vector<int> E[202020];



int ok(int v) {
	int i;
	FOR(i,N) dp[i]=1;
	FOR(i,M) {
		if(D[i]>=v) dp[P[i]]=0;
		else dp[P[i]]=1<<20;
	}
	int ok=0;
	FOR(i,N-M) if(D[i+M]>=v) ok++;
	
	for(i=N;i<TN;i++) {
		dp[i]=min(1<<20,dp[E[i][0]]+dp[E[i][1]]+dp[E[i][2]]-max({dp[E[i][0]],dp[E[i][1]],dp[E[i][2]]}));
	}
	
	return ok>=dp[TN-1];
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>D[i]>>P[i];
		P[i]--;
	}
	FOR(i,N-M) {
		cin>>D[i+M];
	}
	
	TN=N;
	deque<int> Q;
	FOR(i,N) Q.push_back(i);
	while(Q.size()>1) {
		E[TN].push_back(Q[0]);	Q.pop_front();
		E[TN].push_back(Q[0]);	Q.pop_front();
		E[TN].push_back(Q[0]);	Q.pop_front();
		Q.push_back(TN);
		TN++;
	}
	
	
	
	int ret=0;
	for(i=29;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
