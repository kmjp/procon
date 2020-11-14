#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
vector<pair<int,int>> E[202020];
string S;
int AB,AC,BC;
ll D[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>AB>>AC>>BC;
	cin>>S;
	FOR(i,N) {
		if(S[i]=='A') {
			E[i].push_back({N,AB});
			E[i].push_back({N+1,AC});
			E[N+2].push_back({i,0});
			E[N+4].push_back({i,0});
		}
		if(S[i]=='B') {
			E[i].push_back({N+2,AB});
			E[i].push_back({N+3,BC});
			E[N+0].push_back({i,0});
			E[N+5].push_back({i,0});
		}
		if(S[i]=='C') {
			E[i].push_back({N+4,AC});
			E[i].push_back({N+5,BC});
			E[N+1].push_back({i,0});
			E[N+3].push_back({i,0});
		}
	}
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	N+=6;
	FOR(i,N) D[i]=1LL<<60;
	D[0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(D[cur]!=co) continue;
		if(cur==N-7) {
			cout<<co<<endl;
			return;
		}
		FORR(e,E[cur]) if(D[e.first]>co+e.second) {
			D[e.first]=co+e.second;
			Q.push({-D[e.first],e.first});
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
