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

int N;
vector<int> E[2][101010];
int P[2][101010];
int R[2];
int X[101010];

vector<int> E2[101010];
int L[2][101010];

void dfs(int id,int cur) {
	int pre=-1;
	FORR(e,E[id][cur]) {
		dfs(id,e);
		if(pre==-1) {
			pre=L[id][e];
		}
		else {
			E2[pre].push_back(L[id][e]);
			E2[L[id][e]].push_back(pre);
			pre=-1;
		}
	}
	
	if(pre!=-1) L[id][cur]=pre;
	else L[id][cur]=cur;
	
}

void dfs2(int cur,int v) {
	if(X[cur]!=2) {
		assert(X[cur]==v);
		return;
	}
	
	X[cur]=v;
	FORR(e,E2[cur]) dfs2(e,-v);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2) {
		FOR(j,N) {
			cin>>P[i][j+1];
			if(P[i][j+1]==-1) P[i][j+1]=0;
			E[i][P[i][j+1]].push_back(j+1);
		}
	}
	N++;
	FOR(i,N) {
		if(E[0][i].size()%2 != E[1][i].size()%2) return _P("IMPOSSIBLE\n");
		if(E[0][i].size()%2==0) X[i]=2;
	}
	dfs(0,0);
	dfs(1,0);
	
	FOR(i,N) if(X[i]==2) dfs2(i,1);
	_P("POSSIBLE\n");
	for(i=1;i<N;i++) _P("%d%c",X[i],(i==N-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
