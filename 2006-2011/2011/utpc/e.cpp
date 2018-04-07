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
int dp[1010][1010];
int A[1010],B[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> V;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		V.push_back({B[i],i});
	}
	sort(ALL(V));
	FOR(x,N+1) FOR(y,N+1) dp[x][y]=1<<30;
	dp[0][0]=0;
	FOR(i,N) {
		FOR(x,N) {
			dp[i+1][x]=min(dp[i+1][x],dp[i][x]);
			if(dp[i][x]+A[V[i].second]<=B[V[i].second]) dp[i+1][x+1]=min(dp[i+1][x+1],dp[i][x]+A[V[i].second]);
		}
	}
	
	for(i=N;i>=0;i--) {
		if(dp[N][i]<1<<30) return _P("%d\n",i);
	}
	_P("0\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
