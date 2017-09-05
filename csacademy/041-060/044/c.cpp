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
vector<int> V;
set<int> E[101010];
int vis[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>x, V.push_back(x-1);
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	int cur=0;
	vector<int> S;
	S.push_back(0);
	vis[0]=1;
	for(i=1;i<V.size();i++) {
		int tar=V[i];
		vis[tar]=1;
		while(S.size()) {
			x = S.back();
			if(E[x].count(tar)) break;
			
			FORR(e,E[x]) if(vis[e]==0) return _P("0\n");
			S.pop_back();
		}
		if(S.empty()) return _P("0\n");
		S.push_back(tar);
	}
	_P("1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
