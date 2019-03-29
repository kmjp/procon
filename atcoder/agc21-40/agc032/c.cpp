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
set<int> E[101010];
int num=0;
int did[101010];

void dfs(int cur,int step,int tar1,int tar2) {
	if(step>0 && (cur==tar1 || cur==tar2)) return;
	
	int x=*E[cur].begin();
	E[cur].erase(x);
	E[x].erase(cur);
	dfs(x,step+1,tar1,tar2);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	FOR(i,N) if(E[i].size()%2) return _P("No\n");
	FOR(i,N) if(E[i].size()>=6) return _P("Yes\n");
	vector<int> C;
	FOR(i,N) if(E[i].size()==4) C.push_back(i);
	
	if(C.size()>=3) return _P("Yes\n");
	if(C.size()<=1) return _P("No\n");
	
	int num=0;
	while(E[C[0]].size()) {
		dfs(C[0],0,C[0],C[1]);
		num++;
	}
	if(num==4) return _P("No\n");
	else _P("Yes\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
