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

int N,S,X;
vector<int> T[50505];
int E[50505][7];
ll dp[50505][7];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>X;
	S-=2001;
	X-=2001;
	FOR(i,N) {
		cin>>x;
		FOR(j,x) {
			cin>>y;
			T[i].push_back(y-2001);
		}
		FOR(j,7) dp[i][j]=1LL<<60;
	}
	FOR(i,N) {
		FOR(j,7) cin>>E[i][j];
	}
	
	dp[S][0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,(S*7)});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second/7;
		int m=Q.top().second%7;
		Q.pop();
		if(dp[cur][m]!=co) continue;
		if(cur==X) {
			cout<<co<<endl;
			return;
		}
		
		ll ne=co+E[cur][m];
		int nm=ne%7;
		FORR(e,T[cur]) if(dp[e][nm]>ne) {
			dp[e][nm]=ne;
			Q.push({-ne,e*7+nm});
		}
		
	}
	cout<<1048596<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
