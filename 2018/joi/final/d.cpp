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

int N,M,S,T,U,V;
vector<pair<int,int>> E[101010];

ll D[4][202020];
ll F[2][202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T>>U>>V;
	S--,U--,T--,V--;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	
	FOR(i,N) FOR(j,4) D[j][i]=1LL<<60;
	D[0][S]=D[1][T]=D[2][U]=D[3][V]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,S});
	Q.push({0,1000000+T});
	Q.push({0,2000000+U});
	Q.push({0,3000000+V});
	vector<int> cand;
	while(Q.size()) {
		ll co=-Q.top().first;
		int id=Q.top().second/1000000;
		int cur=Q.top().second%1000000;
		Q.pop();
		if(D[id][cur]!=co) continue;
		if(id==0) cand.push_back(cur);
		FORR(e,E[cur]) {
			if(D[id][e.first]>co+e.second) {
				D[id][e.first]=co+e.second;
				Q.push({-D[id][e.first],id*1000000+e.first});
			}
		}
	}
	ll ret=D[2][V];
	FORR(c,cand) {
		F[0][c]=D[2][c];
		F[1][c]=D[3][c];
		FORR(e,E[c]) if(D[0][e.first]+e.second==D[0][c] && D[0][c]+D[1][c]==D[0][T]) {
			F[0][c]=min(F[0][c],F[0][e.first]);
			F[1][c]=min(F[1][c],F[1][e.first]);
		}
		ret=min(ret,F[0][c]+D[3][c]);
		ret=min(ret,F[1][c]+D[2][c]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
