#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,K;
int A[1001],B[1001];
vector<pair<int,int> > E[101];
ll C[1001],D[1001];
int vis[2][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y>>j;
		E[x-1].push_back(make_pair(j,y-1));
		E[y-1].push_back(make_pair(j,x-1));
	}
	
	FOR(i,N) vis[0][i]=1;
	
	FOR(i,K) {
		int cur=i%2,tar=cur^1;
		cin>>D[i];
		ZERO(vis[tar]);
		FOR(x,N) if(vis[cur][x]) {
			FOR(y,E[x].size()) if(E[x][y].first==D[i]) vis[tar][E[x][y].second]=1;
		}
	}
	x=0;
	FOR(i,N) if(vis[K%2][i]) x++;
	_P("%d\n",x);
	FOR(i,N) if(vis[K%2][i]) {
		_P("%d",i+1);
		if(--x) _P(" ");
		else _P("\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
