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
set<int> E[101010][2];
set<pair<int,int>> S;

void add_edge(int a,int b) {
	if(E[a][0].count(b)) {
		E[a][0].erase(b);
		E[b][0].erase(a);
		S.insert({min(a,b),max(a,b)});
		E[a][1].insert(b);
		E[b][1].insert(a);
	}
	else {
		E[a][0].insert(b);
		E[b][0].insert(a);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int id=-1;
	FOR(i,2*(N-1)) {
		cin>>x>>y;
		add_edge(x-1,y-1);
	}
	
	FOR(i,N-1) {
		if(S.empty()) return _P("NO\n");
		x = S.begin()->first;
		y = S.begin()->second;
		S.erase(S.begin());
		E[x][1].erase(y);
		E[y][1].erase(x);
		
		if(E[x][0].size()+E[x][1].size()<E[y][0].size()+E[y][1].size()) {
			swap(x,y);
		}
		// merge y->x
		FORR(e,E[y][0]) if(x!=e) {
			E[e][0].erase(y);
			add_edge(x,e);
		}
		E[y][0].clear();
		
		FORR(e,E[y][1]) if(x!=e) {
			E[e][1].erase(y);
			E[e][1].insert(x);
			E[x][1].insert(e);
			S.erase({min(e,y),max(e,y)});
			S.insert({min(x,e),max(x,e)});
		}
		
	}
	return _P("YES\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
