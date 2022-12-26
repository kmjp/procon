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


int N,M,A;
int D[11];
vector<pair<int,int>> E[10];

ll from[1010];
ll to[1010];
ll dp[1010];
ll to2[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>A;
	FOR(i,M) cin>>D[i];
	FOR(i,N) {
		cin>>x>>y>>k;
		E[x-1].push_back({y,k});
	}
	
	FOR(i,1010) from[i]=1LL<<60;
	from[0]=0;
	FOR(i,M) {
		FOR(j,1010) dp[j]=1LL<<60;
		dp[0]=0;
		FORR(e,E[i]) {
			for(j=1000;j>=0;j--) dp[min(j+e.second,1000)]=min(dp[min(j+e.second,1000)],dp[j]+e.first);
		}
		FOR(j,1001) to[j]=1LL<<60;
		FOR(x,1001) for(y=D[i];y<=1000;y++) to[min(x+y,1000)]=min(to[min(x+y,1000)],from[x]+dp[y]);
		swap(from,to);
	}
	ll ret=1LL<<60;
	for(i=A;i<=1000;i++) ret=min(ret,from[i]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
