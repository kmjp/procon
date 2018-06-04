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

int N,M,X;
int T[101010];
vector<pair<int,int>> E[101010];
ll dist[10101][2][202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X;
	FOR(i,N) cin>>T[i];
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	
	FOR(i,N) FOR(x,X+1) dist[i][0][x]=dist[i][1][x]=1LL<<60;
	priority_queue<pair<ll,int>> P;
	dist[0][0][X]=0;
	P.push({0,X});
	ll mi=1LL<<60;
	while(P.size()) {
		ll co=-P.top().first;
		int cur=P.top().second/1000;
		int type=P.top().second/500%2;
		int left=P.top().second%500;
		P.pop();
		if(dist[cur][type][left]!=co) continue;
		
		if(cur==N-1) mi=min(mi,co);
		
		FORR(e,E[cur]) {
			if(e.second<left && type==0 && T[e.first]==2) continue;
			if(e.second<left && type==1 && T[e.first]==0) continue;
			int nt=(T[e.first]==1)?type:T[e.first]/2;
			int nl=(T[e.first]==1)?max(0,left-e.second):X;
			if(dist[e.first][nt][nl]>co+e.second) {
				dist[e.first][nt][nl]=co+e.second;
				P.push({-dist[e.first][nt][nl], e.first*1000+nt*500+nl});
			}
		}
		
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
