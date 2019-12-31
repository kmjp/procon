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

int N,M,K,S,p,q;
int danger[101010];
vector<int> E[101010];
ll stay[101010];
ll cost[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>S>>p>>q;
	
	MINUS(danger);
	queue<int> Q;
	FOR(i,K) {
		cin>>x;
		danger[x-1]=S;
		Q.push(x-1);
	}
	
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		if(danger[x]<=0) continue;
		FORR(e,E[x]) if(danger[e]<danger[x]-1) {
			danger[e]=danger[x]-1;
			Q.push(e);
		}
	}
	
	FOR(i,N) {
		cost[i]=1LL<<60;
		if(i!=N-1 && danger[i]==S) stay[i]=1LL<<60;
		else if(i!=N-1 && danger[i]>=0) stay[i]=q;
		else if(i!=N-1 && danger[i]<0) stay[i]=p;
	}
	cost[0]=0;
	priority_queue<pair<ll,int>> PQ;
	PQ.push({0,0});
	while(PQ.size()) {
		ll co=-PQ.top().first;
		int cur=PQ.top().second;
		PQ.pop();
		FORR(e,E[cur]) if(cost[e]>co+stay[e]) {
			cost[e]=co+stay[e];
			PQ.push({-cost[e],e});
		}
		
	}
	cout<<cost[N-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
