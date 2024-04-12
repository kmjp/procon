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

int T,N,M,P;
vector<pair<int,int>> E[808];
int W[808],R[808];
vector<int> Ws;
pair<ll,ll> dp[808][808];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>P;
		Ws.clear();
		FOR(i,N) {
			cin>>W[i];
			Ws.push_back(W[i]);
			E[i].clear();
		}
		FOR(i,M) {
			cin>>x>>y>>k;
			E[x-1].push_back({y-1,k});
		}
		
		FOR(i,N) FOR(j,N) dp[i][j]={1LL<<60,0};
		sort(ALL(Ws));
		FOR(i,N) {
			W[i]=lower_bound(ALL(Ws),W[i])-Ws.begin();
		}
		dp[0][W[0]]={0,P};
		
		ll mi=1LL<<60;
		FOR(i,N) {
			int w=Ws[i];
			priority_queue<pair<pair<ll,ll>,int>> Q;
			FOR(j,N) if(dp[j][i].first<(1LL<<60)) {
				Q.push({{-dp[j][i].first,dp[j][i].second},j});
			}
			while(Q.size()) {
				ll num=-Q.top().first.first;
				ll fuel=Q.top().first.second;
				int cur=Q.top().second;
				Q.pop();
				if(dp[cur][i].first!=num||dp[cur][i].second!=fuel) continue;
				if(cur==N-1) mi=min(mi,num);
				FORR2(e,c,E[cur]) {
					int tar=max(i,W[e]);
					
					ll nn=num;
					ll nfuel;
					
					if(fuel>=c) {
						nfuel=fuel-c;
					}
					else {
						ll a=(c-fuel+w-1)/w;
						nn=num+a;
						nfuel=fuel+a*w-c;
					}
					if(dp[e][tar].first>nn||(dp[e][tar].first==nn&&dp[e][tar].second<nfuel)) {
						dp[e][tar]={nn,nfuel};
						if(i==tar) Q.push({{-dp[e][i].first,dp[e][i].second},e});
					}
				}
			}
		}
		
		
		
		if(mi==1LL<<60) mi=-1;
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
