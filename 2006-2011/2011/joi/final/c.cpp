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

int N,M,K;
vector<pair<int,int>> E[3030];
ll dist[3030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y>>r;
		r*=2;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	FOR(i,N) dist[i]=1LL<<60;
	priority_queue<pair<ll,int>> P;
	FOR(i,K) {
		cin>>x;
		dist[x-1]=0;
		P.push({0,x-1});
	}
	ll ma=0;
	while(P.size()) {
		ll co=-P.top().first;
		int cur=P.top().second;
		P.pop();
		if(co!=dist[cur]) continue;
		ma=max(ma,co);
		
		FORR(e,E[cur]) {
			int tar=e.first;
			ll di=e.second;
			if(dist[tar]>co+di) {
				dist[tar]=co+di;
				P.push({-dist[tar],tar});
			}
		}
	}
	
	FOR(i,N) {
		FORR(e,E[i]) {
			ll a=dist[i];
			ll b=dist[e.first];
			ll c=e.second;
			if(a>b) swap(a,b);
			c-=b-a;
			ma=max(ma,b+c/2);
		}
	}
	cout<<(ma+1)/2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
