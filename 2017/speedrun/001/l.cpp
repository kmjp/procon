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
int A[101010];
int vis[101010];
ll tot;

void dfs(int cur,int tar,int st) {
	vis[cur]=1;
	if(cur==tar) tot+=st-1;
	else dfs(A[cur],tar,st+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i],A[i]--;
	
	FOR(i,N) if(vis[i]==0) {
		if(i==A[i]) {
			vis[i]=1;
		}
		else {
			dfs(A[i],i,1);
		}
	}
	if((N-tot)%2==1) return _P("NO\n");
	_P("YES\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
