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
vector<pair<int,int>> E[202020];
ll dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			E[i].clear();
			dp[i]=-1LL<<60;
		}
		FOR(i,M) {
			cin>>x>>y>>k;
			E[x-1].push_back({y-1,k});
			E[y-1].push_back({x-1,-k});
		}
		int ok=1;
		FOR(i,N) if(dp[i]==-1LL<<60) {
			dp[i]=0;
			queue<int> Q;
			Q.push(i);
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				FORR2(e,c,E[cur]) {
					if(dp[e]==-1LL<<60) {
						dp[e]=dp[cur]+c;
						Q.push(e);
					}
					else if(dp[e]!=dp[cur]+c) {
						ok=0;
					}
				}
			}
		}
		if(ok) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
			
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
