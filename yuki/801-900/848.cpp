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

int N,M,P,Q,T;
vector<pair<int,int>> E[2020];
ll D[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>P>>Q>>T;
	P--,Q--;
	FOR(i,M) {
		cin>>x>>y>>r;
		x--,y--;
		E[x].push_back({y,r});
		E[y].push_back({x,r});
	}
	priority_queue<pair<ll,int>> PQ;
	FOR(i,N) {
		if(i!=0 && i!=P && i!=Q) continue;
		FOR(j,N) D[i][j]=1LL<<60;
		D[i][i]=0;
		PQ.push({0,i});
		while(PQ.size()) {
			ll co=-PQ.top().first;
			int cur=PQ.top().second;
			PQ.pop();
			if(D[i][cur]!=co) continue;
			FORR(e,E[cur]) {
				if(D[i][e.first]>co+e.second) {
					D[i][e.first]=co+e.second;
					PQ.push({-D[i][e.first],e.first});
				}
			}
		}
	}
	
	ll ma=-1;
	FOR(x,N) FOR(y,N) {
		ll a=D[0][x]+D[0][y];
		ll b=max(D[P][x]+D[P][y],D[Q][x]+D[Q][y]);
		if(a+b<=T) ma=max(ma,T-b);
	}
	if(D[0][P]+D[P][Q]+D[Q][0]<=T) ma=T;
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
