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
ll X[101],Y[101];
vector<pair<int,int>> E[101];
ll dist[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) dist[x][y]=1LL<<60;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	priority_queue<pair<ll,int>> PQ;
	FORR(e,E[0]) {
		dist[0][e.first]=e.second;
		PQ.push({-e.second, e.first});
	}
	
	while(PQ.size()) {
		int pre=PQ.top().second%100;
		int pre2=PQ.top().second/100;
		ll co=-PQ.top().first;
		PQ.pop();
		if(dist[pre2][pre]!=co) continue;
		
		if(pre==1) {
			cout<<co<<endl;
			return;
		}
		
		FORR(e,E[pre]) {
			int tar=e.first;
			if(dist[pre][tar]<=co+e.second) continue;
			if((X[tar]-X[pre])*(X[pre2]-X[pre])+(Y[tar]-Y[pre])*(Y[pre2]-Y[pre])>0) continue;
			dist[pre][tar]=co+e.second;
			PQ.push({-dist[pre][tar], pre*100+tar});
		}
		
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
