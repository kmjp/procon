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

int T;
int N;
vector<int> E[202020];
vector<pair<int,int>> R;
set<int> S[202020];

void dfs(int cur) {
	set<pair<int,int>> T;
	FORR(e,E[cur]) {
		dfs(e);
		T.insert({-(int)S[e].size(),e});
	}
	while(T.size()>=2) {
		int x=T.begin()->second;
		T.erase(T.begin());
		int y=T.begin()->second;
		T.erase(T.begin());
		R.push_back({*S[x].begin(),*S[y].begin()});
		S[x].erase(S[x].begin());
		S[y].erase(S[y].begin());
		if(S[x].size()) T.insert({-(int)S[x].size(),x});
		if(S[y].size()) T.insert({-(int)S[y].size(),y});
	}
	
	if(T.size()) {
		int x=T.begin()->second;
		swap(S[cur],S[x]);
	}
	
	S[cur].insert(cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,2*N+2) E[i].clear(), S[i].clear();
		FOR(i,2*N) {
			cin>>x;
			E[x].push_back(i+1);
		}
		R.clear();
		dfs(0);
		FORR(r,R) cout<<r.first<<" "<<r.second<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
