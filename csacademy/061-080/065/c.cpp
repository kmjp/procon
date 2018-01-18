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
vector<vector<int>> E;
vector<int> DD;

pair<int,int> farthest(vector<vector<int>>& E, int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(E,e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter(vector<vector<int>>& E) { // diameter,center
	vector<int> D[2];
	D[0].resize(E.size());
	D[1].resize(E.size());
	auto v1=farthest(E,0,0,0,D[0]);
	auto v2=farthest(E,v1.second,v1.second,0,D[0]);
	farthest(E,v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	
	R.first = v2.first;
	R.second.push_back(v1.second);
	R.second.push_back(v2.second);
	DD=D[1];
	return R;
}

vector<int> C;
int vis[101010];
void dfs(int L,int R) {
	int v=0;
	C.push_back(L);
	vis[L]=1;
	
	FORR(e,E[L]) if(vis[e]==0 && DD[L]<DD[e]) {
		dfs(e,R);
		if(vis[R]==0) C.push_back(L);
	}
	FORR(e,E[L]) if(vis[e]==0 && DD[L]>DD[e]) {
		dfs(e,R);
		if(vis[R]==0) C.push_back(L);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	E.resize(N);
	FOR(i,N-1) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	auto p=diameter(E);
	dfs(p.second[0],p.second[1]);
	
	_P("%d\n",C.size()-1);
	FOR(i,C.size()) _P("%d%c",C[i]+1,(i==C.size()-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
