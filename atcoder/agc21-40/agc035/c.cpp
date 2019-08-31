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
vector<pair<int,int>> E;
vector<int> EE[201010];
map<int,int> M;

void add(int x,int y) {
	E.push_back({x,y});
	EE[x].push_back(y);
	EE[y].push_back(x);
}

void dfs(int cur,int pre,int v) {
	if(cur>N) v^=(cur-N);
	else v^=cur;
	M[v]=cur;
	FORR(e,EE[cur]) if(e!=pre) dfs(e,cur,v);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if((N&(N-1))==0) return _P("No\n");
	
	x=1;
	while(x*2<=N) x*=2;
	
	cout<<"Yes"<<endl;
	if(N+1==x*2) {
		for(i=1;i<x;i++) {
			add(i,i+x);
			add(i+x,x);
			add(x,i+N);
			add(i+N,i+x+N);
		}
		add(1,x+N);
	}
	else {
		y=x/2;
		for(i=1;i<y;i++) {
			add(i,i+y);
			add(i+y,y);
			add(y,i+N);
			add(i+N,i+y+N);
		}
		add(1,y+N);
		add(x,x+1);
		add(x+1,1);
		add(1,x+N);
		add(x+N,x+1+N);
		
		dfs(x+N,-1,0);
		
		for(i=x+2;i<=N;i++) {
			add(i,x+N);
			assert(M.count(i));
			add(i+N,M[i]);
		}
		
	}
	
	FORR(e,E) cout<<e.first<<" "<<e.second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
