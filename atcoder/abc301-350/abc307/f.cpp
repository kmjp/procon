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

int N,M,K,D;
vector<pair<int,int>> E[303030];
int ret[303030];
ll dp[303030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({k,y-1});
		E[y-1].push_back({k,x-1});
	}
	FOR(i,N) {
		ret[i]=-1;
		dp[i]=1LL<<60;
	}
	set<pair<int,int>> S;
	
	cin>>K;
	FOR(i,K) {
		cin>>x;
		x--;
		ret[x]=0;
		FORR2(e,t,E[x]) S.insert({e,t});
	}
	cin>>D;
	
	FOR(i,D) {
		int X;
		priority_queue<pair<ll,int>> Q;
		cin>>X;
		while(S.size()&&S.begin()->first<=X) {
			y=S.begin()->first;
			x=S.begin()->second;
			S.erase(S.begin());
			if(ret[x]==-1) {
				ret[x]=i+1;
				dp[x]=y;
				Q.push({-dp[x],x});
			}
		}
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			ret[cur]=i+1;
			Q.pop();
			if(co!=dp[cur]) continue;
			FORR2(e,t,E[cur]) if(ret[t]==-1||ret[t]>=i+1) {
				if(co+e<=X&&co+e<dp[t]) {
					dp[t]=co+e;
					Q.push({-dp[t],t});
				}
				else {
					S.insert({e,t});
				}
			}
			
		}
	}
	
	
	FOR(i,N) cout<<ret[i]<<endl;
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
