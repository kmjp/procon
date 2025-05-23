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

int T;
int N,M;
vector<pair<int,pair<int,int>>> E[101010];
ll T0,T1,T2;
ll dp[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) E[i].clear();
		cin>>T0>>T1>>T2;
		T1=T0-T1;
		T2=T0-T2;
		swap(T1,T2);
		FOR(i,M) {
			cin>>x>>y>>k>>r;
			E[x-1].push_back({y-1,{k,r}});
			E[y-1].push_back({x-1,{k,r}});
		}
		FOR(i,N) dp[i]=1LL<<60;
		dp[N-1]=0;
		priority_queue<pair<ll,int>> Q;
		Q.push({0,N-1});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[cur]!=co) continue;
			FORR2(e,c,E[cur]) {
				ll tar;
				if(co>=T2||co+c.first<=T1) {
					tar=co+c.first;
				}
				else {
					tar=min(T2+c.first,co+c.second);
				}
				if(chmin(dp[e],tar)) Q.push({-tar,e});
			}
		}
		if(dp[0]<=T0) {
			cout<<T0-dp[0]<<endl;
		}
		else {
			cout<<-1<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
