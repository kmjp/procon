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
ll A[101010];
vector<int> E[101010];

ll dfs(int cur,int pre) {
	
	if(E[cur].size()==1) {
		return A[cur];
	}
	
	ll tot=0;
	FORR(e,E[cur]) if(e!=pre) tot+=dfs(e,cur);
	
	ll X=2*A[cur]-tot;
	if(X<0) {
		_P("NO\n");
		exit(0);
	}
	return X;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	if(N==2) {
		if(A[0]==A[1]) return _P("YES\n");
		return _P("NO\n");
	}
	int root=-1;
	FOR(i,N) if(E[i].size()>1) root=i;
	
	if(dfs(root,-1)==0) _P("YES\n");
	else _P("NO\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
