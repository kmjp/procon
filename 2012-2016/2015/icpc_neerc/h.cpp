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

int N,M,K;
int ok[101010], vis[101010];
vector<int> E[101010];
vector<vector<int> > R;

vector<int> dfs(int cur) {
	vis[cur]=1;
	vector<int> v;
	
	FORR(r,E[cur]) if(vis[r]==0) {
		auto v2=dfs(r);
		if(v2.size()) {
			if(v.size()) {
				v.push_back(cur);
				while(v2.size()) v.push_back(v2.back()), v2.pop_back();
				R.push_back(v);
				v.clear();
			}
			else {
				swap(v,v2);
			}
		}
	}
	
	if(ok[cur] && v.size()) {
		R.push_back(v);
		R.back().push_back(cur);
		v.clear();
	}
	else if(v.size() || ok[cur]) {
		v.push_back(cur);
	}
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	FOR(i,K) cin>>x, ok[x]=1;
	FOR(i,N) if(vis[i+1]==0) dfs(i+1);
	
	_P("%d\n",R.size());
	FORR(r,R) {
		_P("%d",r.size()-1);
		FORR(rr,r) _P(" %d",rr);
		_P("\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
