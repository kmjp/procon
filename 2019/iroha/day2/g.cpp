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
vector<pair<int,int>> E[2020];
int X[1010];
int Y[1010];


ll dist[1010][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y>>j;
		E[x-1].push_back({y-1,j});
		E[y-1].push_back({x-1,j});
	}
	FOR(i,N) cin>>X[i]>>Y[i];
	
	FOR(x,1010) FOR(y,2020) dist[x][y]=1LL<<60;
	dist[0][0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second/2020;
		int num=Q.top().second%2020;
		
		Q.pop();
		if(dist[cur][num]!=co) continue;
		
		// flo
		if(dist[cur][min(num+X[cur],K)]>co+Y[cur]) {
			dist[cur][min(num+X[cur],K)]=co+Y[cur];
			Q.push({-(co+Y[cur]),cur*2020+min(num+X[cur],K)});
		}
		FORR(e,E[cur]) {
			if(dist[e.first][num]>co+e.second) {
				dist[e.first][num]=co+e.second;
				Q.push({-(co+e.second),e.first*2020+num});
			}
		}
	}
	
	if(dist[N-1][K]==1LL<<60) dist[N-1][K]=-1;
	
	cout<<dist[N-1][K]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
