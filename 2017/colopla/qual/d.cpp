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
ll X,T[10101];
ll dp[5050][5050];
int pre[5050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>T[i+1];
	for(i=1;i<=N;i++) {
		while(T[i]-T[pre[i]+1]>=X) pre[i]++;
	}
	
	FOR(x,N+1) FOR(y,N+1) dp[x][y]=-1LL<<60;
	dp[0][0]=0;
	for(i=1;i<=N;i++) {
		
		ll ma=0;
		int L=0;
		ll a=X,b=-1LL<<60;
		deque<pair<ll,int>> D;
		//D.push_back({dp[i-1][0]-0,0});
		for(x=1;x<=N;x++) {
			
			while(L+1<=pre[x]) {
				L++;
				a=max(a,dp[i-1][L]+X);
			}
			while(D.size() && D.front().second<=pre[x]) D.pop_front();
			
			dp[i][x]=a;
			if(D.size()) dp[i][x]=max(a,D.front().first+T[x]);
			
			ma=max(ma,dp[i][x]);
			ll add=dp[i-1][x]-T[x];
			while(D.size() && D.back().first<=add) D.pop_back();
			D.push_back({add,x});
		}
		cout<<ma<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
