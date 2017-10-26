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
vector<pair<int,int>> E[5050];
int D[5050][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	FOR(i,N) D[i][0]=D[i][1]=1<<30;
	D[0][0]=0;
	priority_queue<pair<int,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		int co=-Q.top().first;
		int cur=Q.top().second/2;
		int odd=Q.top().second%2;
		Q.pop();
		if(D[cur][odd]!=co) continue;
		
		FORR(e,E[cur]) {
			int tim=max(co,e.second+((co%2)!=(e.second%2)));
			if(D[e.first][odd^1] > tim+1) {
				D[e.first][odd^1]=tim+1;
				Q.push({-D[e.first][odd^1],e.first*2+(odd^1)});
			}
		}
		
	}
	
	
	int ret=min(D[N-1][0],D[N-1][1]);
	if(ret>=1<<30) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
