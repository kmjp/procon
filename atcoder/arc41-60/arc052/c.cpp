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

int N,M;
vector<pair<int,int>> E[10100];
ll dist[10101];
ll mi[10101];
ll from[10101];
ll to[10101];
priority_queue<pair<ll,int>> Q[10100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>r>>x>>y;
		E[x].push_back({y,r});
		E[y].push_back({x,r});
	}
	FOR(i,N) dist[i]=from[i]=mi[i]=1LL<<60;
	from[0]=0;
	Q[0].push({0,0});
	FOR(i,10005) {
		FOR(x,N) to[x]=1LL<<60;
		while(Q[i].size()) {
			auto r=Q[i].top();
			Q[i].pop();
			ll cost=-r.first;
			int cur=r.second;
			if(cost!=from[cur]) continue;
			
			mi[cur]=min(mi[cur],from[cur]);
			dist[cur]=min(dist[cur],from[cur]+1LL*i*(i+1)/2);
			
			FORR(e,E[cur]) {
				if(e.second==0) {
					if(from[e.first]>from[cur]+1 && from[cur]+1<mi[e.first]) {
						from[e.first]=from[cur]+1;
						Q[i].push({-from[e.first],e.first});
					}
				}
				else {
					if(to[e.first]>from[cur] && from[cur]+i<mi[e.first]) {
						to[e.first]=from[cur];
						Q[i+1].push({-to[e.first],e.first});
					}
				}
			}
		}
		swap(from,to);
	}
	
	FOR(i,N) cout<<dist[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
