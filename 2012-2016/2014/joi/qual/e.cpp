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

int N,K;
int R[5050],C[5050];
int dist[5050][5050];
int cost[5050][5050];
vector<int> E[5050];
ll d[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>C[i]>>R[i];
	}
	FOR(i,K) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) {
		cin>>C[i]>>R[i];
		FOR(x,N) dist[i][x]=cost[i][x]=1<<29;
		dist[i][i]=0;
		queue<int> Q;
		Q.push(i);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			if(dist[i][x]<=R[i]) cost[i][x]=C[i];
			
			FORR(e,E[x]) if(dist[i][e]>dist[i][x]+1) {
				dist[i][e]=dist[i][x]+1;
				Q.push(e);
			}
		}
		d[i]=1LL<<40;
	}
	
	priority_queue<pair<ll,int>> Q;
	d[0]=0;
	Q.push({0,0});
	while(Q.size()) {
		int cur=Q.top().second;
		ll co=-Q.top().first;
		Q.pop();
		if(co!=d[cur]) continue;
		FOR(i,N) if(d[i]>co+cost[cur][i]) {
			d[i]=co+cost[cur][i];
			Q.push({-d[i],i});
		}
	}
	
	cout<<d[N-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
