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

int N,M,C;
vector<pair<int,int>> E[202020];
ll dist[202020];
int did[202020];
ll TL;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>C;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
		TL+=r;
	}
	FOR(i,N) dist[i]=1LL<<60;
	dist[0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	
	ll mi=1LL<<60;
	
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		
		if(co!=dist[cur]) continue;
		did[cur]=1;
		
		FORR(e,E[cur]) if(dist[e.first] > co+e.second) {
			dist[e.first] = co+e.second;
			Q.push({-dist[e.first],e.first});
		}
		FORR(e,E[cur]) if(did[e.first]) TL-=e.second;
		mi=min(mi,dist[cur]*C + TL);
		
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
