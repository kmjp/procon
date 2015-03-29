#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int D[101000];
vector<int> E[101000];
int ng,ml;

void dfs(int cur,int dep) {
	int i;
	D[cur]=dep;
	FORR(r,E[cur]) {
		if(D[r]==-1) dfs(r,dep+1);
		else if(D[r]<D[cur]-1) ml=max(ml,(D[cur]+1-D[r]));
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	
	FOR(i,N) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	MINUS(D);
	dfs(0,0);
	
	_P("%d %d\n",1+(ml==N),N-(ml%2));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
