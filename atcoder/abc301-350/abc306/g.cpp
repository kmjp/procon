#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,M;
vector<int> E[2][202020];
ll dp[2][202020];
ll G[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			E[0][i].clear();
			E[1][i].clear();
			dp[0][i]=dp[1][i]=1LL<<30;
			G[i]=0;
		}
		FOR(i,M) {
			cin>>x>>y;
			E[0][x-1].push_back(y-1);
			E[1][y-1].push_back(x-1);
		}
		FOR(j,2) {
			dp[j][0]=0;
			queue<int> Q;
			Q.push(0);
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				FORR(e,E[j][cur]) {
					if(dp[j][e]==1LL<<30) {
						dp[j][e]=dp[j][cur]+1;
						Q.push(e);
					}
					else {
						G[e]=__gcd(G[e],dp[j][cur]+1-dp[j][e]);
					}
				}
			}
		}
		ll TG=0;
		for(i=1;i<N;i++) if(dp[0][i]<1LL<<30&&dp[1][i]<1<<30) {
			TG=__gcd(TG,dp[0][i]+dp[1][i]);
			TG=__gcd(TG,G[i]);
		}
		if(TG==0) {
			cout<<"No"<<endl;
		}
		else {
			while(TG%2==0) TG/=2;
			while(TG%5==0) TG/=5;
			if(TG==1) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
