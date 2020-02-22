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
vector<int> E[202020];
int M[202020];
int C[202020];
map<int,int> memo[202020];


int dfs2(int cur,int pre,int v) {
	if(memo[cur].count(v)) return memo[cur][v];
	int ret=0;
	FORR(e,E[cur]) if(e!=pre && e<v) ret+=1+dfs2(e,cur,v);
	
	return memo[cur][v]=ret;
	
}

void dfs(int cur,int pre) {
	if(cur>1) {
		M[cur]=max(pre,M[pre]);
		if(cur>M[pre]) {
			C[cur]=C[pre]+1+dfs2(cur,pre,M[cur]);
		}
		else {
			C[cur]=C[pre]+dfs2(cur,pre,M[cur])-dfs2(cur,pre,M[pre]);
		}
	}
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	dfs(1,1);
	for(i=2;i<=N;i++) cout<<C[i]<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
